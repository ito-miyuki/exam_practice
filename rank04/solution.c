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

// it passed Grademe 
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

int is_same(char *str1, char *str2)
{
    if (strcmp(str1, str2) == 0)
        return (1);
    else
        return (0);
}

/*
i は execute 関数から渡されてきますが、
これは現在のコマンドの終わり（例えば、"|" や ";"）までの引数の数を表しています。
cd <directory> という形式では、引数の数は 2 になります。
*/ 
int ft_cd(char **argv, int i)
{
    if (i != 2)
        return (print_error("error: cd: bad arguments", NULL));
    if (chdir(argv[1]) == -1)
        return (print_error("error: cannot change directory to ", argv[1]));
    return (0);
}

// int excute(char **argv, int i, char **envp)
// {
//     int fd[2];
//     int status;
//     int has_pipe = 0;
//     if (argv[i] && is_same(argv[i], "|"))
//         has_pipe = 1;
    
//     if (!has_pipe && is_same(*argv, "cd"))
//         return (ft_cd(argv, i));
    
//     if (has_pipe && pipe(fd) == -1)
//         return (print_error("error: fatal", NULL));
    
//     int pid = fork();
//     if (pid == 0)
//     {
//         argv[i] = 0;
//         if (has_pipe)
//         {
//             if (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
//                 return (print_error("error: fatal", NULL));
//         }
//         if (is_same(*argv, "cd"))
//             return (ft_cd(argv, i));
//         execve(*argv, argv, envp);
//         return (print_error("error: cannot execute ", *argv));
//     }
//     waitpid(pid, &status, 0);
//     if (has_pipe)
//     {
//         if (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
//             return (print_error("error: fatal", NULL));
//     }
//     return (WIFEXITED(status) && WEXITSTATUS(status));
// }

int execute(char **argv, int i, char **envp)
{
    int fd[2]; // パイプ用のファイルディスクリプタ。fd[0]は読み取り端、fd[1]は書き込み端
    int status; // 子プロセスの終了ステータス
    int has_pipe = 0; // パイプの有無を示すフラグ。初期値は0（パイプなし）

    // argv[i] が '|' であれば、パイプがあると設定
    if (argv[i] && is_same(argv[i], "|"))
        has_pipe = 1;
    
    // パイプがない場合、かつコマンドが 'cd' であれば、cd コマンドを処理
    if (!has_pipe && is_same(*argv, "cd"))
        return (ft_cd(argv, i));
    
    // パイプがある場合、pipe を作成。失敗した場合はエラーメッセージを表示
    if (has_pipe && pipe(fd) == -1)
        return (print_error("error: fatal", NULL));
    
    // 新しいプロセスを作成
    int pid = fork();
    if (pid == 0) // 子プロセスの場合
    {
        /*
        // コマンドを終了させるために argv[i] を NULL(0)に書き換える。
        現在はパイプ、セミコロン、ヌルのいずれかを指している状態。
        パイプがあれば、パイプ前までのコマンドを実行する。
        */
        argv[i] = 0;

        //　もしパイプがあるなら、標準出力をパイプの書き込み端にリダイレクト
            // これにより、子プロセスが標準出力に書き込むデータがパイプに送られる
        if (has_pipe)
        {
            if (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
                return (print_error("error: fatal", NULL));
        }

        // コマンドが 'cd' であれば、cd コマンドを処理
        if (is_same(*argv, "cd"))
            return (ft_cd(argv, i));
        
        execve(*argv, argv, envp); //引数は、実行パス(/bin/ls) char**型のリスト envリスト
        // execve が失敗した場合のエラーメッセージ
        return (print_error("error: cannot execute ", *argv));
    }

    // 親プロセスの場合
    waitpid(pid, &status, 0); // 子プロセスの終了を待つ

    // パイプがある場合の処理
    if (has_pipe)
    {
        // 標準入力をパイプの読み取り端にリダイレクト
        // これにより、親プロセス（または次のプロセス）が標準入力からデータを読み取ると、それがパイプから取得される
        if (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1)
            return (print_error("error: fatal", NULL));
    }
    
    // 子プロセスの終了ステータスを返す
    return (WIFEXITED(status) && WEXITSTATUS(status));
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

            while (argv[i] && !is_same(argv[i], "|") && !is_same(argv[i], ";"))
                i++;
            if (i)
                status = excute(argv, i, envp);
        }
    }
    return (status);
}