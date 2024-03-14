/*
- first of all, skip space/tabs untill the first word starts
- then, start printing letters untill it reaches space, tab or null terminator
*/

#include <unistd.h>

void ft_first_word(char *str)
{
	int i = 0;
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		while ((str[i] != ' ' && str[i] != '\t') && str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
}


int main(int argc, char **argv)
{
	if (argc == 2)
		ft_first_word(argv[1]);
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
