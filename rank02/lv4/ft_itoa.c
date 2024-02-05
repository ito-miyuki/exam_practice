#include <stdlib.h>

int count_len(int n)
{
	int count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	char *res;
	int num_len = count_len(nbr);
	int i = 0;
	int num_len2 = count_len(nbr);

	res = malloc(sizeof(char) * (num_len) + 1);
	if (!res)
		return (NULL);
	if (nbr < 0)
	{
		res[i] = '-';
		nbr = -nbr;
		i++;
	}
	if (nbr == 0)
	{
		res[i] = '0';
		i++;
	}
	else
	{
		while (nbr > 0)
		{
			res[num_len - 1] = nbr % 10 + '0';
			nbr = nbr / 10;
			num_len--;
		}
	}
	res[num_len2] = '\0';
	return (res);
}
// #include <stdio.h>
// int main()
// {
// 	int nbr = 42;
// 	char *res =  ft_itoa(nbr);
// 	printf("%s\n", res);
// }