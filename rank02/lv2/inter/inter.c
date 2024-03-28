#include <unistd.h>

/*
s1の文字がs２にあるか最後まで調べる
同じ文字見つけたら、これまでにその文字をプリントしたかどうかチェック
もしまだプリントしてなければ書いて、breakでループを抜けてs１の次の文字へ移る
*/
int can_print(char *s1, char c, int i)
{
	int j = 0;
	while (j < i)
	{
		if (s1[j] == c)
			return (0);
		j++;
	}
	return (1);
}

void ft_inter(char *s1, char *s2)
{
	int i = 0;
	int j;

	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
			{
				if (can_print(s1, s1[i], i))
					write(1, &s1[i], 1);
				break;
			}
			else
				j++;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);	
}


///////////

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