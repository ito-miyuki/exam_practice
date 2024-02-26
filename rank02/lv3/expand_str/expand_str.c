#include <unistd.h>

void ft_expand_str(char *str)
{
    int i = 0;
    int word_started = 0;
    while (str[i] != '\0')
    {
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        if (str[i] != '\0' && word_started == 1)
            write(1, "   ", 3);
        while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
        {
            write(1, &str[i], 1);
            i++;
            word_started = 1;
        }
    }
}

int main (int argc, char **argv)
{
    if (argc == 2)
        ft_expand_str(argv[1]);
    write(1, "\n", 1);
    return (0);
}

//other solution
int main (int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        int word_started = 0;

        while (argv[1][i] != '\0')
        {
            while (argv[1][i] == ' ' || argv[1][i] == '\t')
                i++;
            if (word_started != 0 && argv[1][i] != '\0')
                write(1, "   ", 3);
            while (argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0')
            {
                write(1, &argv[1][i], 1);
                i++;
                word_started = 1;
            }
        }
    }
    write(1, "\n", 1);
    return (0);
}

