#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        int j;
        int repeat_count = 0;
        while (argv[1][i])
        {
            if (argv[1][i] >= 65 && argv[1][i] <= 90)
                repeat_count = argv[1][i] - 'A' + 1;
            else if (argv[1][i] >= 97 && argv[1][i] <= 122)
                repeat_count = argv[1][i] - 'a' + 1;
            else
                repeat_count = 1;
            j = 0;
            while (j < repeat_count)
            {
                write(1, &argv[1][i], 1);
                j++;
            }
                i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
