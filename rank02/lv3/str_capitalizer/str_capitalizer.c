// もう一度確認して

//これならpassする
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_str_capitalizer(char *str)
{
	int	idx;

	idx = 1;
	if (str[0] >= 'a' && 'z' >= str[0])
		str[0] -= 32;
	ft_putchar(str[0]);
	while (str[idx] != '\0')
	{
		if (str[idx] >= 'A' && 'Z' >= str[idx])
			str[idx] += 32;
		if ((str[idx] >= 'a' && 'z' >= str[idx]) && (str[idx - 1] == ' '
				|| str[idx - 1] == '\t'))
			str[idx] -= 32;
		ft_putchar(str[idx]);
		idx++;
	}
}

int	main(int argc, char **argv)
{
	int	idx;

	if (argc < 2)
		ft_putchar('\n');
	else
	{
		idx = 1;
		while (idx < argc)
		{
			ft_str_capitalizer(argv[idx]);
			ft_putchar('\n');
			idx++;
		}
	}
	return (0);
}

//これはpassするかわからない
#include <unistd.h>

void str_capitalizer(char **str)
{
    int i = 1;
    int j;

    while (str[i] != NULL)
    {
        j = 0;
        while (str[i][j] != '\0')
        {
            if (str[i][j] >= 'a' && str[i][j] <= 'z')
            {
                if (j == 0 || str[i][j - 1] == ' ' || str[i][j - 1] == '\t')
                    str[i][j] -= 32;
            }
            else if (str[i][j] >= 'A' && str[i][j] <= 'Z')
            {
                if (j != 0 && str[i][j - 1] != ' ' && str[i][j - 1] != '\t')
                    str[i][j] += 32;
            }
            write(1, &str[i][j], 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc > 1)
    	str_capitalizer(argv);
    return (0);
}

//これだとpassしない
// void str_capitalizer(char *str)
// {
// 	int i = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (i == 0 && (str[i] >= 'a' && str[i] <= 'z'))
// 			str[i] = str[i] - 32;
// 		else if ((str[i - 1] == ' ' && (str[i] >= 'a' && str[i] <= 'z')))
// 			str[i] = str[i] - 32;
// 		else if (str[i - 1] != ' ' && (str[i] >= 'A' && str[i] <= 'Z'))
// 			str[i] = str[i] + 32;
// 		write(1, &str[i], 1);
// 		i++;
// 	}
// }

// int main(int argc, char **argv)
// {
// 	if (argc > 1)
// 	{
// 		int i  = 0;
// 		while (argv[i])
// 		{
// 			str_capitalizer(argv[i]);
// 			write(1, "\n", 1);
// 			i++;
// 		}
// 	}
// 	else
// 		write(1, "\n", 1);
// 	return (0);
// }
