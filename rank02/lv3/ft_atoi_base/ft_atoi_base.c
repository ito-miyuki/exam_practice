#include <stdio.h>

// int	ft_tolower(int c)
// {
// 	if (c >= 65 && c <= 90)
// 		c = c + 32;
// 	return (c);
// }

// int	in(char c, char *base, int id)
// {
// 	int	i;

// 	i = 0;
// 	while (base[i] != '\0' && i < id)
// 	{
// 		if (base[i] == c)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int	ft_atoi_base(const char *str, int str_base)
// {
// 	int	idx;
// 	int	sign;
// 	int	result;

// 	idx = 0;
// 	sign = 1;
// 	result = 0;
// 	if (str[idx] == '-')
// 	{
// 		sign = -1;
// 		idx++;
// 	}
// 	while (str[idx] != '\0' && in(ft_tolower(str[idx]), "0123456789abcdef", str_base))
// 	{
// 		result *= str_base;
// 		if (str[idx] >= '0' && str[idx] <= '9')
// 			result += str[idx] - '0';
// 		else if (str[idx] >= 'A' && str[idx] <= 'Z')
// 			result += str[idx] - '7';
// 		else if (str[idx] >= 'a' && str[idx] <= 'z')
// 			result += str[idx] - 'W';
// 		idx++;
// 	}
// 	return (result * sign);
// }
/*
int main()
{
    const char *str = "Ceci permet de decouvrir le fonctionnement de ton ft_atoi_base.";
    int str_base = 16;

    int result = ft_atoi_base(str, str_base);
    printf("Converted value of '%s' in base %d is %d\n", str, str_base, result);

    return 0;
}

*/

int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
    int neg = 1;
    int res = 0;

    if (str[i] == '-')
    {
        neg = -neg;
        i++;
    }
    while (str[i] != '\0')
    {
        res = res * str_base;
        if (str[i] >= '0' && str[i] <= '9')
            res = res + str[i] - '0';
        else if (str[i] >= 'A' && str[i] <= 'Z')
            res = res + str[i] - '7';
        else if (str[i] >= 'a' && str[i] <= 'z')
            res = res + str[i] - 'W';
        i++;
    }
    return (res * neg);
}