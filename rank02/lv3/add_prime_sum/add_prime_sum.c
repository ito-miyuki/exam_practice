#include <unistd.h>
#include <stdio.h>

void ft_ptnbr(int n)
{
    if (n >= 10)
        ft_ptnbr(n / 10);
    char num = n % 10 + '0';
    write (1, &num, 1);
}

int ft_atoi(char *str)
{
    int sign;
    int res;

    res = 0;
    sign = 1;
    while (*str != '\0')
    {
        if (*str == '-' || *str == '+')
        {
            if (*str == '-')
                sign = -1;
            str++;
        }
        if (*str >= '0' && *str <= '9')
            res = res * 10 + (*str - '0');
        else
            return (-1);
        str++;
    }
    return (res * sign);
}

int main(int argc, char **argv)
{
    int i;
    int start_n = 2;
    int n;
    int sum = 0;
    if (argc != 2)
    {
        write(1, "0", 1);
        return (0);
    }
    n = ft_atoi(argv[1]);
    if (n < 0)
    {
        write(1, "0", 1);
        return (0);
    }
    if (argc == 2)
    {
        while (start_n <= n)
        {
            int flag = 0;
            i = 2;
            while (start_n > i)
            {
                if (start_n % i == 0)
                    flag = 1;
                i++;
            }
            if (flag == 0)
                sum += start_n;
            start_n++;
        }
        ft_ptnbr(sum);
    }
    write(1, "\n", 1);
    return (0);
}