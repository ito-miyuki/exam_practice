
int ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
void ft_swap(char *a, char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
char    *ft_strrev(char *str)
{
	int len = ft_strlen(str) - 1;
	int i = 0;
	while (str[i] != '\0' && i < len)
	{
		ft_swap(&str[i], &str[len]);
		i++;
		len--;
	}
	return (str);
}

#include <stdio.h>
int main()
{
	char str[] = "Hello";
	char *res = ft_strrev(str);
	printf("%s", res);
	return (0);
}