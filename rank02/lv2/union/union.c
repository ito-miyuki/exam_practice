// haven't had it in Grademe but should be correct!

#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int is_double(char *str, char c, int n)
{
	int i = 0;
	while (i < n)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
void ft_union(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	int len1 = ft_strlen(s1);
	int len2 = ft_strlen(s2);
	while (s1[i] != '\0')
	{
		if (!(is_double(s1, s1[i], i)))
			write(1, &s1[i], 1);
		i++;
	}
	while (s2[j] != '\0')
	{
		if (!(is_double(s2, s2[j], j)) && !(is_double(s1, s2[j], len1)))
			write(1, &s2[j], 1);
		j++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}