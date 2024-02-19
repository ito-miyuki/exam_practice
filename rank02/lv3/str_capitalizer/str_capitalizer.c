// もう一度確認して

#include <unistd.h>

void str_capitalizer(char **str)
{
    int i = 1;
    int j;

    while (str[i] != NULL)
    {
        j = 0;
        while (str[i][j] != '\0')
        {
            if (str[i][j] >= 'a' && str[i][j] <= 'z')
            {
                if (j == 0 || str[i][j - 1] == ' ' || str[i][j - 1] == '\t')
                    str[i][j] -= 32;
            }
            else if (str[i][j] >= 'A' && str[i][j] <= 'Z')
            {
                if (j != 0 && str[i][j - 1] != ' ' && str[i][j - 1] != '\t')
                    str[i][j] += 32;
            }
            write(1, &str[i][j], 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc > 1)
    	str_capitalizer(argv);
    return (0);
}
