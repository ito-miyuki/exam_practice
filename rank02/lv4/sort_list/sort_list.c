// 覚えて！
/*
lstのtempを作って、tempの指しているものをlstにする
lstの次がヌルじゃない間、cmp関数をlstのデータと次のデータで実行して、
その結果が０ならスワップする
スワップしたらlstはtempが指しているものに変更(lstを最新に更新)
スワップが必要ないなら、次のデータに進む
ループが終わったら、tempが持ってるものをlstに入れてlstを返して終了
*/
#include <stdlib.h>
#include "list.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *tmp;

	tmp = lst;
	while(lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			ft_swap(&lst->data, &lst->next->data);
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}

//勉強
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list * temp;

	temp = lst;
	while (lst->next != NULL)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			ft_swap(&lst->data, &lst->next->data);
			lst = temp;
		}
		else
			lst = lst->next;
	}
	lst = temp;
	return (lst);
}


// other solutions
// #include "list.h"
// #include <stdlib.h>

// t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
// {
// 	int	swap;
// 	t_list	*tmp;

// 	tmp = lst;
// 	while(lst->next != NULL)
// 	{
// 		if (((*cmp)(lst->data, lst->next->data)) == 0)
// 		{
// 			swap = lst->data;
// 			lst->data = lst->next->data;
// 			lst->next->data = swap;
// 			lst = tmp;
// 		}
// 		else
// 			lst = lst->next;
// 	}
// 	lst = tmp;
// 	return (lst);
// }

// main func for testing

// int cmp(int node_left, int node_right)
// {
// 	if (node_left <= node_right)
// 		return (1);
// 	else
// 	{
// 		return (0);
// 	}
// }

// int main(void)
// {
// 	t_list	*lst;
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;
// 	t_list	*temp_list;
// 	int i;

// 	node1 = malloc(sizeof(t_list));
// 	node2 = malloc(sizeof(t_list));
// 	node3 = malloc(sizeof(t_list));

// 	lst = node1;
// 	node1 -> next = node2;
// 	node2 -> next = node3;
// 	node3 -> next = NULL;

// 	node1 -> data = -10;
// 	node2 -> data = 10;
// 	node3 -> data = 5;

// 	lst = sort_list(lst, cmp);
// 	i = 1;
// 	while (lst)
// 	{
// 		printf("node %d: %d\n", i, lst->data);
// 		temp_list = lst;
// 		lst = lst -> next;
// 		i++;
// 		free(temp_list);
// 	}
// 	return (0);
// }