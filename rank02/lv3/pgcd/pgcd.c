#include <stdio.h>
#include <stdlib.h>


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
