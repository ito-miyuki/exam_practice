#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int print_error(char *msg, char *argv)
{
	while (*msg)
		write(2, msg++, 1);
	if (argv)
		while(*argv)
			write(2, argv++, 1);
	write(2, "\n", 1);
    return (1);
}

int ft_cd(char **argv, int i)
{
    if (i != 2)
        return (print_error("error: cd: bad arguments", NULL));
    if (chdir(argv[i]) == -1)
        return (print_error("error: cd: cannot change directory to ", argv[i]));
    return (0);
}

int exec(char **argv, int i, char **envp)
{
    int fd[2];
    int status;
    int has_pipe = argv[i] && !strcmp(argv[i], "|"); 
    // --> it i checking if the argv[i] exist and if it is true, has_pipe int fill be 1 (true).

    if (!has_pipe && strcmp(*argv, "cd") == 0) //it means if it is cd
        return (ft_cd(argv, i));

    if (has_pipe && pipe(fd) == -1)
        return (print_error("error: fatal", NULL));

    int pid = fork();
    if (!pid)
    {
        argv[i] = 0;
        if (has_pipe && (dup2(fd[i], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
            return (print_error("error: fatal", NULL));
        if (strcmp(*argv, "cd") == 0) // it means if it is cd
            return (ft_cd(argv, i));
        execve(*argv, argv, envp);
        return (print_error("error: cannot excute ", *argv));
    }

    waitpid(pid, &status, 0);
    if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        return (print_error("error: fatal", NULL));
    return (WIFEXITED(status) && WEXITSTATUS(status));
}

int main(int argc, char **argv, char **envp)
{
    int i = 0;
    int status = 0;

    if (argc > 1) //1の時は./microshellしか書かれてない時
    {
        //このループは、コマンドライン引数を解析し、適切な区切り（ */| や ;）で区切られたコマンドを順次実行するためのもの
        while (argv[i] && argv[++i])
        {
            argv += i;
            i = 0;
            while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
                i++;
            if (i)
                status = exec(argv, i, envp);
        }
    }
    return status;
}