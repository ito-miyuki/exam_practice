//勉強した方がいい

void ft_swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void sort_int_tab(int *tab, unsigned int size)
{
	int i = 0;
	int bubble = 0;
	if (size <= 1)
		return;
	while (bubble < size)
	{
		i = 0;
		while (i < (size - 1))
		{
			if (tab[i] > tab[i + 1])
				ft_swap(&tab[i], tab[i + 1]);
			i++;
		}
		bubble++;
	}
}