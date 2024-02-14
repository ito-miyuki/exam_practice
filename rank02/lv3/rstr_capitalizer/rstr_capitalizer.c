#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        write(1, "\n", 1);
        return (0);
    }
    if (argc > 1)
    {
        int i = 1;
        while (argv[i] != '\0')
        {
            int j = 0;
            while (argv[i][j] != '\0')
            {
                if (argv[i][j] >= 'A' && 'Z' >= argv[i][j])
			        argv[i][j] += 32;
                if ((argv[i][j] >= 'a' && argv[i][j] <= 'z') && (argv[i][j + 1] == ' ' || argv[i][j + 1] == '\t' || argv[i][j + 1] == '\0'))
                {
                    argv[i][j] -= 32;
                    write(1, &argv[i][j], 1);
                }
                else
                     write(1, &argv[i][j], 1);
                j++;
            }
            write(1, "\n", 1);
            i++;
            // else
            // {
            //         if (!(argv[i][j] >= 'a' && argv[i][j] <= 'z') && (argv[i][j] != ' ' && argv[i][j] != '\t'))
            //         {
            //             argv[i][j] += 32;
            //             write(1, &argv[i][j], 1);
            //         }
            //         else if ((argv[i][j] == ' ' || argv[i][j] == '\t'))
            //             write(1, &argv[i][j], 1);
            //         else
            //             write(1, &argv[i][j], 1);
            // }
        }
    }
    return (0);
}


// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// void	ft_rstr_capitalizer(char *str)
// {
// 	int	idx;

// 	idx = 0;
// 	while (str[idx] != '\0')
// 	{
// 		if (str[idx] >= 'A' && 'Z' >= str[idx])
// 			str[idx] += 32;
// 		if ((str[idx] >= 'a' && 'z' >= str[idx]) && (str[idx + 1] == ' '
// 				|| str[idx + 1] == '\t' || str[idx + 1] == '\0'))
// 			str[idx] -= 32;
// 		ft_putchar(str[idx]);
// 		idx++;
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	int	idx;

// 	if (argc < 2)
// 		ft_putchar('\n');
// 	else
// 	{
// 		idx = 1;
// 		while (idx < argc)
// 		{
// 			ft_rstr_capitalizer(argv[idx]);
// 			ft_putchar('\n');
// 			idx++;
// 		}
// 	}
// 	return (0);
// }