/*
	バブルソート。比較と交換は、要素の数分だけでじゅうぶん。
	１巡目で一番小さいものがいちばん最初に来る
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
	int bubble = 0; //iteration
	if (size <= 1)
		return;
	while (bubble < size) //比較と交換は、要素の数の分で完了するから
	{
		i = 0;
		while (i < (size - 1)) //配列内の要素を全て見ていく
		{
			if (tab[i] > tab[i + 1]) //右にある数字の方が大きいなら
				ft_swap(&tab[i], &tab[i + 1]); //並び替える
			i++;
		}
		bubble++; //次に小さい数字を正しい場所に並び替える
	}
}

//勉強


// #include <stdio.h>
// int main()
// {
// 	unsigned int size = 5;
// 	int *tab = {3, 9, 343, 1, 3}
// 	sort_int_tab(tab, size);
// 	unsigned int i = 0;
// 	while (i < size) 
// 	{
//         printf("%d ", tab[i]);
// 		i++;
//     }
//     printf("\n");
// }