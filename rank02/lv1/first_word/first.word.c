#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	if (argc == 2)
	{
		while (argv[1][i] == 9 || argv[1][i] == 32)
			i++;
		while ((argv[1][i] != 9 && argv[1][i] != 32) && argv[1][i] != '\0')
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	//	write(1, "\0", 1);
	}
	write(1, "\n", 1);
	return (0);
}

//other soutions
void first_word(char *str)
{
	int i = 0;

		if (str[i] == ' ' || str[i] == '\t')
		{
				while(str[i] == ' ' || str[i] == '\t')
					i++;
		}
		while ((str[i] != ' ' && str[i] != '\t') && str[i] != '\0')
		{
			// if (str[i + 1] == ' ' || str[i] == '\t')
			// 	break;;
			write(1, &str[i], 1);
			i++;
		}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		first_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
