#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = ft_strlen(argv[1]) - 1;
		while (i >= 0)
		{
			write(1, &argv[1][i], 1);
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}


//other solutions
#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int len = ft_strlen(argv[1]);
        if (len == 0)
        {
            write(1, "\n", 1);
            return (0);
        }
        int i = len - 1;
        while (i >= 0)
        {
            write(1, &argv[1][i], 1);
            i--;
        }
    }
    write(1, "\n", 1);
    return (0);
}

