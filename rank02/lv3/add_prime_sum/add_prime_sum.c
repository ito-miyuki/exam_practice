#include <unistd.h>
#include <stdlib.h>

int ft_atoi(char *str)
{
    int res = 0;
    int i = 0;
    int neg = 1;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            neg = -1;
        i++;
    }
    while (str[i] != '\0')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res * neg);
}

void putnbr(int num)
{
    char c;
    if (num < 0)
    {
        write(1, "-", 1);
        num = -num;
    }
    if (num == 0)
    {
        write(1, "0", 1);
        return ;
    }
    if (num > 9)
    {
        putnbr(num / 10);
        c = num % 10 + '0';
        write(1, &c, 1);

    }
    else
    {
        c = num + '0';
        write(1, &c, 1);
    }
}

int prime_num(char *argv)
{
    int num = ft_atoi(argv);
    if (num < 0)
    {
        write(1, "0\n", 2);
        exit (0);
    }
    int i;
    int k = 2;
    int sum = 0;
    int prime;
    while (k <= num)
    {
        i = 2;
        prime = 1;
        while (i < k)
        {
            if (k % i == 0)
                prime = 0;
            i++;
        }
        if (prime == 1)
            sum += k;
        k++;
    }
    return (sum);
}


int main(int argc, char **argv)
{
    if (argc == 2)
    {
        putnbr(prime_num(argv[1]));
        write(1, "\n", 1);
        return (0);
    }
    write(1, "0\n", 2);
    return (0);
}


//other solutions

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