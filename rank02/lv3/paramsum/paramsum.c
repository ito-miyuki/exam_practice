#include <unistd.h>

// putnbr もう一度確認して

void ft_putnbr(int n)
{
    char c;
    if (n < 0)
    {
        write(1, "-", 1);
		// max intのところテストでも必要？
        // if (n == -2147483648)
        // {
        //     ft_putnbr(-(n / 10));
        //     c = '8';
        //     write(1, &c, 1);
        //     return;
        // }
        n = -n;
    }
    if (n > 9)
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    else
    {
        c = n + '0';
        write(1, &c, 1);
    }
}


int main(int argc, char **argv)
{
	if (argc == 1)
		write(1, "0", 1);
	else if (argc > 1)
		ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}