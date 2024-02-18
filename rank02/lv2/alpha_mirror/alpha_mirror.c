#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        while(argv[1][i] != '\0')
        {
            if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
            {
                argv[1][i] = 90 - argv[1][i] + 65;
            }
            else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
            {
                argv[1][i] = 122 - argv[1][i] + 97;
            }
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}

//other solutions
void alpha_mirror(char *str)
{
	int i = 0;
	int dis_to_a = 0; // how far is it now to a. distance to a
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			dis_to_a = str[i] - 'a';
			str[i] = 'z' - dis_to_a;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			dis_to_a = str[i] - 'A';
			str[i] = 'Z' - dis_to_a;
		}
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		alpha_mirror(argv[1]);
	write(1, "\n", 1);
	return (0);
}