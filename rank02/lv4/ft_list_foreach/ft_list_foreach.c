#include "ft_list.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    while (begin_list != NULL) //リストにまだnodeがあるあいだ(NULLじゃない間)
    {
        if (begin_list->data) //dataが有効な値を指していたら
            (*f)(begin_list->data); //それに対して関数を実行
        begin_list = begin_list->next; //次のnodeへ
    }
}


void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}

//練習
void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    t_list *list_ptr;

    list_ptr = begin_list;

    while (list_ptr)
    {
        (*f)(list_ptr->data);
        list_ptr = list_ptr->next;
    }
}

