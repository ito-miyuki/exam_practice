#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL || *begin_list == NULL) //ポインタ自体が無効　または　リストが空
		return;

	t_list *cur = *begin_list;

	if (cmp(cur->data, data_ref) == 0) //現在のノードの「データ」が参照データと等しい場合
	{
		*begin_list = cur->next; //begin listがさしているものをcur(temp)を使って次のものにし、
		free(cur); // //トップだったものを削除
		ft_list_remove_if(begin_list, data_ref, cmp); // 更新されたリスト（現在の要素が削除された後のリスト）に対して同じ処理を繰り返す
	}
    else
    {
        // 現在のノードが重複していない場合、次のノードに対して処理を適用
        ft_list_remove_if(&(*begin_list)->next, data_ref, cmp);
    }
}

//　github からのsolution
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    if (begin_list == NULL || *begin_list == NULL)
        return ;

    t_list *cur = *begin_list;

    if (cmp(cur->data, data_ref) == 0)
    {
        *begin_list = cur->next;
        free(cur);
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    cur = *begin_list;
    ft_list_remove_if(&cur->next, data_ref, cmp);
}

