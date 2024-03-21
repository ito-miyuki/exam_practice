#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// void ft_putchar(char c) {
//     write(1, &c, 1);
// }

// // 文字列の単語の数を数える関数
// int word_count(char *str) {
//     int i = 0;
//     int count = 0;
//     while (str[i]) 
//     {
//         //1こ前の文字が空白だったらカウントする
//         //一番最初の文字も数えるためにi == 0も条件にいれる
//         if ((str[i-1] == ' ' || str[i-1] == '\t' || i == 0) 
//         && (str[i] != ' ' && str[i] != '\t')) 
//         {
//             count++;
//         }
//         i++;
//     }
//     return count;
// }

// // 単語を分割して、それらの配列を返す関数
// char **split_words(char *str) 
// {
//     int wc = word_count(str);
//     char **words = malloc(sizeof(char*) * (wc + 1)); // 単語の配列にメモリを割り当てる
//     int i = 0, j, word_len;

//     for (int w = 0; w < wc; w++) {
//         while (str[i] == ' ' || str[i] == '\t') i++; // 空白をスキップ
//         word_len = 0;
//         j = i;
//         // 単語の長さを計算
//         while (str[j] && str[j] != ' ' && str[j] != '\t') {
//             word_len++;
//             j++;
//         }
//         words[w] = (char*)malloc(sizeof(char) * (word_len + 1)); // 単語にメモリを割り当てる
//         strncpy(words[w], &str[i], word_len); // 単語をコピー
//         words[w][word_len] = '\0'; // ヌル終端を追加
//         i += word_len;
//     }
//     words[wc] = NULL; // 配列の終端を示す
//     return words;
// }

// int main(int argc, char **argv) {
//     if (argc == 2) {
//         char **words = split_words(argv[1]);
//         for (int i = word_count(argv[1]) - 1; i >= 0; i--) {
//             // 単語を逆順に出力
//             write(1, words[i], strlen(words[i]));
//             if (i > 0) {
//                 ft_putchar(' '); // 単語の間にスペースを挿入
//             }
//             free(words[i]); // 割り当てたメモリを解放
//         }
//         free(words); // 単語の配列のメモリを解放
//     }
//     ft_putchar('\n');
//     return 0;
// }

//other solution
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_space(char c)
{
	if ((c == ' ') || (c == '\t'))
		return (1);
	return (0);
}

void	rev_wstr(char *str)
{
	int	idx;
	int	j;
	int	first_word;

	idx = 0;
	first_word = 1;
	while (str[idx] != '\0')
		idx++;
	while (idx >= 0)
	{
		while (idx >= 0 && (str[idx] == '\0' || is_space(str[idx])))
			idx--;
		j = idx;
		while (j >= 0 && !is_space(str[j]))
			j--;
		if (first_word == 0)
			ft_putchar(' ');
		write(1, str + j + 1, idx - j);
		first_word = 0;
		idx = j;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	ft_putchar('\n');
	return (0);
}