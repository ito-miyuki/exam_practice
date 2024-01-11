#include <stdlib.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}


char    *ft_strdup(char *src)
{
	char *copy;
	copy = malloc(sizeof(char) * (ft_strlen(src) + 1));
	int i = 0;
	//int j = 0;
	if (!copy)
		return (NULL);
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

#include <stdio.h>

int main()
{
	char *str = "copy this!";
	printf("%s\n", ft_strdup(str));
}