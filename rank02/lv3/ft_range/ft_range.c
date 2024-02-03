#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
    int *res;
    int range;
    int i = 0;

    if (start <= end) //プラスに向かって行くケース
        range = (end - start) + 1;
    else if (end < start) //マイナスに向かって行くケース
        range = (start - end) + 1;
    res = malloc(sizeof(int) * range);
    if (!res)
        return (0);
    if (start == end)
    {
        res[i] = start;
        printf("%d", res[i]);
    }
    else if (start < end)//プラスに向かって行くケース
    {
        while (i < range)
        {
            res[i] = start;
            printf("%d", res[i]); // delete it 
            i++;
            start++;
        }
    }
    else if (end < start) //マイナスに向かって行くケース
    {
        while (i < range)
        {
            res[i] = start;
            printf("%d", res[i]); // delete it 
            i++;;
            start--;
        }
    }
    return (res);
}

int main()
{
    ft_range(0, -5);
    return (0);
}