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

#include <stdio.h>

int main()
{
    const char *str = "-42";
    printf("%d\n", ft_atoi(str));
}