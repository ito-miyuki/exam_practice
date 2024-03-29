#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start, int end)
{
	int size;
	int *res;
	int i = 0;
	if (start <= end)
		size = (end - start) + 1;
	else if (end < start)
		size = (start - end) + 1;
	res = malloc(sizeof(int) * size);
	if (!res)
		return (0);
	if (start == end)
		res[i] = start;
	else if (start < end)
	{
		while (i < size)
		{
			res[i] = end;
			end--;
			i++;
		}
	}
	else if (end < start)
	{
		while (i < size)
		{
			res[i] = end;
			end++;
			i++;
		}
	}
	return (res);
}

int main() {
    int start = -7; // 開始値
    int end = -3;   // 終了値

    // ft_range 関数を呼び出して結果を取得
    int *result = ft_rrange(start, end);

    // 結果を出力
    if (result == NULL) {
        printf("メモリの割り当てに失敗しました。\n");
    } else {
        printf("result: [");
        // 配列の要素を出力
        for (int i = 0; i < abs(end - start) + 1; i++) {
            printf("%d", result[i]);
            if (i != abs(end - start)) {
                printf(", ");
            }
        }
        printf("]\n");
        // 結果のメモリを解放
        free(result);
    }

    return 0;
}