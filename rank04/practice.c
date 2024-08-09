/*
もしこれを実行したら　./a.out /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell

argv = {
    "./a.out",
    "/bin/ls",
    "|",
    "/usr/bin/grep",
    "microshell",
    ";",
    "/bin/echo",
    "i",
    "love",
    "my",
    "microshell",
    NULL
}
argc = 11


*/

#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int print_error(char *msg, char *arg)
{
    while (*msg)
        write(2, msg++, 1);
    if (arg)
    {
        while (*arg)
            write(2, arg++, 1);
    }
    write(2, "\n", 1);
    return (1);
}

int ft_cd(char **argv, int i)
{
    if (i != 2)
        return (print_error("error: cd: bad arguments", NULL));
    if (chdir(argv[1]) == -1)
        return (print_error("error: cd: cannot change directory to ", argv[1]));
    return (0);
}

int excute(char **argv, int i, char **envp)
{
    int fd[2];
    int status;
    int has_pipe = 0;

    if (argv[i] && is_same(argv[i], "|"))
        has_pipe = 1;
    
    if (!has_pipe && is_same(*argv, "cd"))
        return (ft_cd(argv, i));
    
    if (has_pipe && pipe(fd) == -1)
        return (print_error("error: fatal", NULL));
    
    int pid = fork();
    if (pid == 0)
    {
        argv[i] = 0;

        if (has_pipe)
        {
            if (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 && close(fd[1]) == -1)
                return (print_error("error: fatal", NULL));
        }
        if (is_same(*argv, "cd"))
            return (ft_cd(argv, i));
        execve(*argv, argv, envp);
        return (print_error("error: cannot excute ", *argv));
    }
    waitpid(pid, &status, 0);

    if (has_pipe)
        {
            if (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 && close(fd[1]) == -1)
                return (print_error("error: fatal", NULL));
        }
    return (WIFEXITED(status) && WEXITSTATUS(status));
}


int is_same(char *str1, char *str2)
{
    if (strcmp(str1, str2) == 0)
        return (1);
    else
        return (0); 
}

int main(int argc, char **argv, char **envp)
{
    int i = 0;
    int status = 0;

    if (argc > 1)
    {
        while (argv[i] && argv[++i])
        {
            argv += i;
            i = 0;
            while (argv[i] && !is_same(argv, "|") && !is_same(argv, ";"))
                i++;
            if (i)
                status = excute(argv, i, envp);
        }
    }
    return (status);
}