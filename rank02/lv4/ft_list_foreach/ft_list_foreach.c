#include "ft_list.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    while (begin_list != NULL) //リストにまだnodeがあるあいだ
    {
        if (begin_list->data) //dataが有効な値を指していたら
            (*f)(begin_list->data); //それに対して関数を実行
        begin_list = begin_list->next; //次のnodeへ
    }
}


//練習
void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    while (begin_list != NULL)
    {
        if (begin_list->data)
            (*f)(begin_list->data);
        begin_list = begin_list->next;
    }
}