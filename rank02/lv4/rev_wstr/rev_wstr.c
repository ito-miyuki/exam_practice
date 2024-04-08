#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*
文字列の後ろに前に向かっていく
単語が見つかったら、その単語を逆順にして出力。
今指してるところが文章の最初の単語の始まりじゃない限りは
単語の間にはスペースを書く
*/

// int	is_space(char c)
// {
// 	if ((c == ' ') || (c == '\t'))
// 		return (1);
// 	return (0);
// }

// void rev_wstr(char *str)
// {
// 	int i = 0;
//     int begin = 0;
//     int word_start = 0;
//     int word_end = 0;
	
//     while (is_space(str[i]) || str[i] == '\0')
//         i++;
//     begin = i;
//     while (str[i])
//         i++;
//     while (begin <= i)
//     {
//         while (is_space(str[i]) || str[i] == '\0')
//             i--;
//         word_end = i;
//         while (!(is_space(str[i])) && str[i] != '\0')
//             i--;
//         word_start = i + 1;
//         int flag = word_start;
//         while (word_start <= word_end)
//         {
//             write(1, &str[word_start], 1);
//             word_start++;
//         }   
//         if (flag != begin)
//             write(1, " ", 1);
//     }
// }

void rev_wstr(char *str)
{
	int i = 0;
	int begin = 0;
	int word_end = 0;
	int word_start = 0;
	int flag = 0;
	while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
		i++;
	begin = i;
	while (str[i] != '\0')
		i++;
	while (begin <= i)
	{
		while (str[i] == ' ' || str[i] == ' ' || str[i] == '\0')
			i--;
		word_end = i;
		while (str[i] != ' ' && str[i] != ' ' && str[i] != '\0')
			i--;
		word_start = i + 1;
		flag = word_start;
		while (word_start <= word_end)
		{
			write(1, &str[word_start], 1);
			word_start++;
		}
		if (flag != begin)
			write(1, " ", 1);
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	write(1, "\n", 1);
}

// this one below doesn't work with space at beginning/end
// int	is_space(char c)
// {
// 	if ((c == ' ') || (c == '\t'))
// 		return (1);
// 	return (0);
// }

// void	rev_wstr(char *str)
// {
// 	int	i;
// 	int	j;
// 	int	first_word;

// 	i = 0;
// 	first_word = 1;
// 	while (str[i] != '\0')
// 		i++;
// 	while (i >= 0)
// 	{
// 		while (i >= 0 && (str[i] == '\0' || is_space(str[i])))
// 			i--;
// 		j = i;
// 		while (j >= 0 && !is_space(str[j]))
// 			j--;
// 		if (first_word == 0)
// 			write(1, " ", 1);
// 		write(1, str[j + 1], i - j);
// 		first_word = 0;
// 		i = j;
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 		rev_wstr(argv[1]);
// 	write(1, "\n", 1);
// 	return (0);
// }
