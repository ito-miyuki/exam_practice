// use "unsigned int long", otherwise it will crash when ag is negative num
// 1 is a power of 2, you should remeber that!

int is_power_of_2(unsigned int n)
{
	unsigned int long num; 
	num = 1;
	if (n == 1)
		return (1);
	if (n < 0)
		return (0);
	while  (n > num)
		num = num * 2;
	if (num == n)
		return (1);
	return (0);
}

// #include <stdio.h>
// int main()
// {
// 	unsigned int n = -3;
// 	int res = is_power_of_2(n);
// 	printf("%d\n", res);
// }