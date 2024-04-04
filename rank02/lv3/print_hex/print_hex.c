#include <unistd.h>

// int ft_atoi(char *str)
// {
//     int n = 0;

//     while (*str != '\0')
//     {
//         n = n * 10;
//         n = n + *str - '0';
//         str++;
//     }
//     return (n);
// }
// void    print_hex(int n)
// {
//     char *hex_digit = "0123456789abcdef";

//     if (n >= 16)
//         print_hex(n / 16);
//     write (1, &hex_digit[n % 16], 1);
// }


// int main(int argc, char **argv)
// {
//     if (argc == 2)
//         print_hex(ft_atoi(argv[1]));
//     write (1, "\n", 1);
//     return (0);
// }


// 練習

int ft_atoi(char *num)
{
    int res;
    int i = 0;
    int neg = 1;
    res = 0;
    while(num[i] != '\0')
    {
        if (num[i] == '-' || num[i] == '+')
        {
            if (num[i] == '-')
                neg = -1;
            i++;
        }
        while (num[i] != '\0')
        {
            res = res * 10 + (num[i] - '0');
            i++;
        }
    }
    return (res * neg);
}
void print_hex(int num)
{
    char *hex_num = "0123456789abcdef";
    
    if (num >= 16)
        print_hex(num / 16);
    write(1, &hex_num[num % 16], 1);
}

void print_hex(int num)
{
    char *hex = "0123456789abcdef";
    if (16 >= num)
        print_hex(num / 16);
    write(1, &hex[num % 16], 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        print_hex(ft_atoi(argv[1]));
    write(1, "\n", 1);
    return (0);
}

// #include <stdio.h>
// int main()
// {
//     int res = ft_atoi("15");
//     printf("%d", res);
// }