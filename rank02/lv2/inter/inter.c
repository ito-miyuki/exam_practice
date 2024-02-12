#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int ft_strchr(char *str, char c, int idx)
{
	int i = 0;
	while (str[i] != '\0' && i < idx)
	{
		if (str[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0;
		int j = 0;
		int total_len = ft_strlen(argv[2]);
		while (argv[1][i] != '\0')
		{
			if (ft_strchr(argv[2], argv[1][i], total_len) && !ft_strchr(argv[1], argv[1][i], i))
			{
				write(1, &argv[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}