#include <stdio.h>
#include <stdlib.h>

void putnum(int num)
{
	char c;
	if (num < 10)
	{
		c = num + '0';
		write(1, &c, 1);
	}
	else
	{
		putnum(num / 10);
		c = num % 10 + '0';
		write(1, &c, 1);
	}
}

void ft_pgcd(char *char_num1, char *char_num2)
{
	int num1 = atoi(char_num1);
	int num2 = atoi(char_num2);
	int div = 1;
	int res = 0;
	while (div < num1 || div < num2)
	{
		if ((num1 % div == 0) && (num2 % div == 0))
			res = div;
		div++;
	}
	putnum(res);
}

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_pgcd(argv[1], argv[2]);
	write(1, "\n", 1);
}


/*
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int num1 = atoi(argv[1]);
		int num2 = atoi(argv[2]);
		int n = 1;
		int denominator = 1;
		while (n < num1 || n < num2)
		{
			if (num1 % n == 0 && num2 % n == 0)
				denominator = n;
			n++;
		}
		printf("%d", denominator);
	}
	printf("\n");
	return (0);
}

*/