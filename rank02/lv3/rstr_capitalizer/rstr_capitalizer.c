/*
大文字なら小文字に変換
小文字なら、次の文字がタブ、スペース、ヌルの場合に大文字に変更して出力
*/

#include <unistd.h>

void rstr_capitalizer(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if ((str[i] >= 'a' && str[i] <= 'z') &&
		 (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
			str[i] -= 32;
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	int i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			rstr_capitalizer(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
}

// other solution
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

//other solutions
#include <unistd.h>

void rstr_capitalizer(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if ((str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
		}
		else if ((str[i] >= 'A' && str[i] <= 'Z') && (str[i - 1] == ' ' || str[i - 1] != '\t' || str[i - 1] != '\0'))
			str[i] += 32;
		else if ((str[i] >= 'A' && str[i] <= 'Z'))
			str[i] += 32;
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		int i = 1;
		while (argv[i] != NULL)
		{
			rstr_capitalizer(argv[i]);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}