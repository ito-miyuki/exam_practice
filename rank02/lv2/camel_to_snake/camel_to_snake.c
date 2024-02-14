#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		while (argv[1][i])
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				argv[1][i] += 32;
				write(1, "_", 1);
			}
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

// other solution
#include <unistd.h>

void snake_to_camel(char *argv)
{
    int i = 0;
    while (argv[i] != '\0')
    {
        if (argv[i] != '_')
            write(1, &argv[i], 1);
        if (argv[i] == '_')
        {
            i++;
            argv[i] -= 32;
            write(1, &argv[i], 1);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        snake_to_camel(argv[1]);
    write(1, "\n", 1);
    return (0);
}
