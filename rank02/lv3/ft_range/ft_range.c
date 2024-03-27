#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int *res;
	int size;
	int i = 0;
	if (start <= end) //プラスに向かって行くケース
		size = (end - start) + 1;
	else if (end < start) //マイナスに向かって行くケース
		size = (start - end) + 1;
	res = malloc(sizeof(int) * size);
	if (!res)
		return (0);
	if (start == end)
		res[i] = start;
	else if (start < end) //プラスに向かって行くケース
	{
		while (i < size)
		{
			res[i] = start;
			i++;
			start++;
		}
	}
	else if (end < start) //マイナスに向かって行くケース
	{
		while (i < size)
		{
			res[i] = start;
			i++;
			start--;
		}
	}
	return (res);
}

// #include <stdio.h>
// #include <stdlib.h>

// // ft_range 関数のプロトタイプ宣言
// int *ft_range(int start, int end);

// int main() {
//     int start = 0; // 開始値
//     int end = 0;   // 終了値

//     // ft_range 関数を呼び出して結果を取得
//     int *result = ft_range(start, end);

//     // 結果を出力
//     if (result == NULL) {
//         printf("メモリの割り当てに失敗しました。\n");
//     } else {
//         printf("result:[");
//         // 配列の要素を出力
//         for (int i = 0; i < (end - start + 1); i++) {
//             printf("%d", result[i]);
//             if (i != (end - start)) {
//                 printf(", ");
//             }
//         }
//         printf("]\n");
//         // 結果のメモリを解放
//         free(result);
//     }

//     return 0;
// }