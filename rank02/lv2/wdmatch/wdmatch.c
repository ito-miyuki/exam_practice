// Haven't had it in Grademe but it should be correct!

#include <unistd.h>

void ft_putstr(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void ft_wdmatch(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	while (s2[j] != '\0')
	{
		if (s1[i] == s2[j])
			i++;
		j++;
	}
	if (!s1[i])
		ft_putstr(s1);
}

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_wdmatch(argv[1], argv[2]);
	return (0);
}

// #include <unistd.h>

// void ft_putstr(char const *str)
// {
// 	int i = 0;

// 	while (str[i])
// 		write(1, &str[i++], 1);
// }

// int	main(int argc, char const *argv[])
// {
// 	int i = 0;
// 	int j = 0;

// 	if (argc == 3)
// 	{
// 		while (argv[2][j])
// 			if (argv[2][j++] == argv[1][i])
// 				i += 1;
// 		if (!argv[1][i])
// 			ft_putstr(argv[1]);
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }