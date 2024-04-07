#include <stdio.h>

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

int get_digit(char c, int digits_in_base)
{
	int max_digit;
	if (digits_in_base <= 10)
		max_digit = digits_in_base + '0';
	else
		max_digit = digits_in_base - 10 + 'a';

	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= max_digit)
		return (10 + c - 'a');
	else
		return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
	int result = 0;
	int sign = 1;
	int digit;

	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	while ((digit = get_digit(to_lower(*str), str_base)) >= 0)
	{
		result = result * str_base;
		result = result + (digit * sign);
		++str;
	}
	return (result);
}


// #include <stdio.h>
// int main()
// {
//     const char *str = "Ceci permet de decouvrir le fonctionnement de ton ft_atoi_base.";
//     int str_base = 16;

//     int result = ft_atoi_base(str, str_base);
//     printf("%d\n", result);

//     return 0;
// }

//this one below didn't go pass Norminette

/*
atoiとほとんど同じだけど res = res * 10 + (str[i] - '0');の部分を変更
かける数字がbaseによって変わるから、最初にres = res * baseをして、
その後はif条件文
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
		// else
		// 	return (res * neg);
        i++;
    }
    return (res * neg);
}

#include <stdio.h>
int main()
{
    const char *str = "Ceci permet de decouvrir le fonctionnement de ton ft_atoi_base.";
    int str_base = 16;

    int result = ft_atoi_base(str, str_base);
    printf("%d\n", result);

    return 0;
}