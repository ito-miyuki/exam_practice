// this is for just writing a string

#include <unistd.h>

char *snake_to_camel(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '_')
			i++;
		if (str[i] != '_' && str[i - 1] == '_' && (str[i] >= 'a' && str[i] <= 'z'))
			str[i] -= 32;
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		snake_to_camel(argv[1]);
	return (0);
}

// this is for returning a converted string

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int count_char(char *str)
{
	int i = 0;
	int counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '_')
			counter++;
		i++;
	}
	return (counter);
}
int ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char *snake_to_camel(char *str)
{
	int i = 0;
	int res_i = 0;
	char *res;
	res = malloc(sizeof(char) * (ft_strlen(str) - count_char(str) + 1));
	while (str[i] != '\0')
	{
		if (str[i] == '_')
			i++;
		if (str[i] != '_' && str[i - 1] == '_' && (str[i] >= 'a' && str[i] <= 'z'))
			str[i] -= 32;
		res[res_i] = str[i];
		i++;
		res_i++;
	}
	res[res_i] = '\0';
	return (res);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *res = snake_to_camel(argv[1]);
		printf("result is %s\n", res);
	}
	return (0);
}