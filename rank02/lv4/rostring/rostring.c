// #include <unistd.h> // For write

// //これだけしかpassしない
// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// int	is_space(char c)
// {
// 	if ((c == ' ') || (c == '\t'))
// 		return (1);
// 	return (0);
// }

// void	ft_print_first_word(char *str, int begin_space)
// {
// 	while (str[begin_space] != '\0' && !is_space(str[begin_space]))
// 	{
// 		ft_putchar(str[begin_space]);
// 		begin_space++;
// 	}
// }

// void	rostring(char *str)
// {
// 	int	i;
// 	int	begin_space;

// 	begin_space = 0;
// 	while (str[begin_space] != '\0' && is_space(str[begin_space]))
// 		begin_space++;
// 	i = begin_space;
// 	while (str[i] != '\0' && !is_space(str[i]))
// 		i++;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] != '\0' && !is_space(str[i]) && is_space(str[i - 1]))
// 		{
// 			while (str[i] != '\0' && !is_space(str[i]))
// 			{
// 				ft_putchar(str[i]);
// 				i++;
// 			}
// 			ft_putchar(' ');
// 		}
// 		i++;
// 	}
// 	ft_print_first_word(str, begin_space);
// }
// int	main(int argc, char **argv)
// {
// 	if (argc > 1)
// 		rostring(argv[1]);
// 	ft_putchar('\n');
// 	return (0);
// }


#include <unistd.h>

void	ft_rostring(char *str)
{
	int	i = 0;
	int	first_word = 0;
    int fd = 0;
    int word_started = 0;

	first_word = 0;
    while (str[first_word] == '\0' || str[first_word] == ' ' || str[first_word] == '\t')
		first_word++;
    while (str[first_word] != '\0' && str[first_word] != ' ' && str[first_word] != '\t')
		first_word++;
	i = first_word;
    while (str[i] == '\0' || str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= 33 && str[i] <= 126)
		{
			if ((str[i - 1] == ' ' || str[i - 1] == '\t') && word_started == 1)
                fd = write(1, " ", 1);
            fd = write(1, &str[i], 1);
		}
        word_started = 1;
		i++;
	}
    if (fd != 0)
        write(1, " ", 1);
	while (str[first_word] != ' ' && str[first_word] != '\t' && str[first_word] != '\0')
    {
        write(1, &str[first_word], 1);
        first_word++;
    }
}

int main(int argc, char **argv)
{
    int i = 1;
    if (argc > 1)
    {
        while (i < argc)
        {
            ft_rostring(argv[i]);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}

