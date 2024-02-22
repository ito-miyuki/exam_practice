#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int ft_atoi(char *str)
{
	int i = 0;
	int res = 0;
	int neg = 1;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * neg);
}

void ft_putnbr(int num)
{
	char c;
	if (num < 0)
	{
		num = -num;
		write(1, "-", 1);
	}
	if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
	{
		c = num + '0';
		write(1, &c, 1);
	}
}

void tab_mult(char *num)
{
	int int_num = ft_atoi(num);
	int i = 1;
	while (i <= 9)
	{
		ft_putnbr(i);
		write(1, " ", 1);
		write(1, "x", 1);
		write(1, " ", 1);
		ft_putnbr(int_num);
		write(1, " ", 1);
		write(1, "=", 1);
		write(1, " ", 1);
		ft_putnbr(i * int_num);
		write(1, "\n", 1);
		i++;
	}
}
int main(int argc, char **argv)
{
	if (argc == 2)
		tab_mult(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}



//other solutions
void ft_putnbr(int num)
{
	char c;
	if (num < 10)
	{
		c = num + 48;
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(num / 10);
		num = num % 10;
		c = num + 48;
		write(1, &c, 1);
	}
}

int ft_atoi(char *num)
{
	int i = 0;
	int res = 0;
	while (num[i] != '\0')
	{
		res = res * 10 + (num[i] - '0');
		i++;
	}
	return (res);
}

void ft_tab_mult(char *char_num)
{
	int num = ft_atoi(char_num);
	int i = 1;
	while (i <= 9)
	{
		ft_putnbr(i);
		write(1, " ", 1);
		write(1, "x", 1);
		write(1, " ", 1);
		ft_putnbr(num);
		write(1, " ", 1);
		write(1, "=", 1);
		write(1, " ", 1);
		ft_putnbr(i * num);
		write(1, "\n", 1);
		i++;
	}
}
int main(int argc, char **argv)
{
	if (argc == 2)
		ft_tab_mult(argv[1]);
	else
		write(1, "\n", 1);	
	return (0);
}