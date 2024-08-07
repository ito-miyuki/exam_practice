#include <string.h>
#include <unistd.h>

int exec(char **argv, int i, char **envp)
{

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
}