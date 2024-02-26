#include <unistd.h> // For write

//これだけしかpassしない
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_space(char c)
{
	if ((c == ' ') || (c == '\t'))
		return (1);
	return (0);
}

void	ft_print_first_word(char *str, int begin_space)
{
	while (str[begin_space] != '\0' && !is_space(str[begin_space]))
	{
		ft_putchar(str[begin_space]);
		begin_space++;
	}
}

void	rostring(char *str)
{
	int	i;
	int	begin_space;

	begin_space = 0;
	while (str[begin_space] != '\0' && is_space(str[begin_space]))
		begin_space++;
	i = begin_space;
	while (str[i] != '\0' && !is_space(str[i]))
		i++;
	while (str[i] != '\0')
	{
		if (str[i] != '\0' && !is_space(str[i]) && is_space(str[i - 1]))
		{
			while (str[i] != '\0' && !is_space(str[i]))
			{
				ft_putchar(str[i]);
				i++;
			}
			ft_putchar(' ');
		}
		i++;
	}
	ft_print_first_word(str, begin_space);
}
int	main(int argc, char **argv)
{
	if (argc > 1)
		rostring(argv[1]);
	ft_putchar('\n');
	return (0);
}