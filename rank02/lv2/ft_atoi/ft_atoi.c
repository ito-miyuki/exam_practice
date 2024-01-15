// the answer
int ft_atoi(const char *str)
{
    int res = 0;
    int sign = 1;

    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        res = res * 10 + *str - '0';
        str++;
    }   
    return (sign * res);
}

//refactor
int ft_atoi(const char *str)
{
    int i = 0;
    int res = 0;
    int negative = 1;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-')
    {
        negative = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - '0';
        i++;
    }
    return (res * negative);
}

#include <stdio.h>

int main()
{
    const char *str = "-42";
    printf("%d\n", ft_atoi(str));
}