
int		max(int* tab, unsigned int len)
{
	if (len == 0)
		return (0);
	int max_num;
	int i = 0;
	max_num = tab[0];
	while (i < len)
	{
		if (tab[i] > max_num)
			max_num = tab[i];
		i++;
	}
	return (max_num);
}


#include <stdio.h>
int main()
{
	int tab[] = {3, -7, 0, 900};
	unsigned int len = 4;
	printf("%d\n", max(tab, len));
}