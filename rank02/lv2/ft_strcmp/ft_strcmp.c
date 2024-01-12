int    ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	int res;
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			return (res);
		}
	}
	return (0);
}
/*
#include <stdio.h>
int main()
{
	char *s1 = "Hello";
	char *s2 = "Hel";

	int res = ft_strcmp(s1, s2);
	printf("%d\n", res);
}
*/
