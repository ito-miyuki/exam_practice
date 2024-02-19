//もう一度勉強必要
#include <stdio.h>
#include <stdlib.h>

void ft_prime(char *str)
{
	int num = atoi(str);
	int divider = 2;
	if (num == 1)
	{
		printf("1");
		return;
	}
	while (num >= divider)
	{
		if (num % divider == 0)
		{
			printf("%d", divider);
			if (num != divider)
				printf("*");
			num = num / divider;
		}
		else
			divider++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		ft_prime(argv[1]);
	printf("\n");
	return (0);
}

// #include <stdio.h>
// #include <stdlib.h>

// void ft_prime(char *str)
// {
//     int num = atoi(str); // 正しく文字列から整数への変換を行う
//     int divider = 2;
//     if (num == 1) {
//         printf("1");
//         return;
//     }
//     while (num >= divider) {
//         if (num % divider == 0) {
//             printf("%d", divider);
//             num = num / divider; // 素因数で割る
//             if (num != 1) // numが1になったら、最後の素因数であり、末尾に'*'を追加しない
//                 printf("*");
//         } else {
//             divider++; // 割り切れなかった場合、dividerを増加させる
//         }
//     }
// }

// int main(int argc, char **argv) {
//     if (argc == 2) {
//         ft_prime(argv[1]);
//     }
//     printf("\n");
//     return (0);
// }
