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

//other solutions
void repeat_alpha(char *str)
{
	int i = 0;
	int counter;
	int repeat;
	while (str[i] != '\0')
	{
		counter = 0;
		repeat = 0;
		if  (str[i] >= 'a' && str[i] <= 'z')
		{
			repeat = str[i] - 'a' + 1;
			while (counter < repeat)
			{
				write(1, &str[i], 1);
				counter++;
			}
		}
		else if  (str[i] >= 'A' && str[i] <= 'Z')
		{
			repeat = str[i] - 'A' + 1;
			while (counter < repeat)
			{
				write(1, &str[i], 1);
				counter++;
			}
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		repeat_alpha(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}