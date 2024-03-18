#include <stdio.h>
#include <stdlib.h>

/*
how many words?
what is the str_len of each words?
allocate memory for 2d array
alocate memory for each elements in 2d array
*/

int word_count(char *str)
{
	int i = 0;
	int counter = 0;
	while (str[i] != '\0')
	{
		if (counter == 0 || ((str[i] != ' ' && str[i] != '\t')
			&& (str[i - 1] == ' ' || str[i - 1] == '\t'))) //一個前が区切り文字だったら
			counter++;
		i++;
	}
	return (counter);
}

char    **ft_split(char *str)
{

	int word_len = word_count(str);
	int arr_i = 0;
	int i = 0;
	int res_i = 0;
	int word_pos;
	char **res = malloc(sizeof(char *) * (word_len + 1));
	if (!res)
		return (NULL);
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] != '\0')
		{
			word_pos = i;
			while (str[word_pos] != '\0' && str[word_pos] != ' ' && str[word_pos] != '\t')
				word_pos++; //単語の区切りを見つけたらword potion - 1分のメモリを確保
			res[arr_i] = malloc(sizeof(char) * (word_pos - i + 1)); //iから区切り文字を見つけるまでどれくらい移動したか
			if (!res[arr_i])
				return (NULL);
			while (i < word_pos)
			{
				res[arr_i][res_i] = str[i];
				res_i++;
				i++;
			}
			res[arr_i][res_i] = '\0';
			arr_i++;
			res_i = 0;
		}
	}
	res[arr_i] = (NULL);
	return (res);
}

#include <stdio.h>

int main(void) {
    char *str = "apple banana pear cherry"; 
    char **words = ft_split(str); 

    for (int i = 0; words[i] != NULL; i++) {
        printf("Word %d: %s\n", i + 1, words[i]);
    }

    for (int i = 0; words[i] != NULL; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}


//練習

// how many words?
// what is the str_len of each words?
// allocate memory for 2d array
// alocate memory for each elements in 2d array

// int words_count(char *str)
// {
// 	int i = 0;
// 	int count = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (count == 0 || ((str[i] != ' ' && str[i] != '\t') && (str[i - 1] == ' ' || str[i - 1] == '\t')))
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }


// char **ft_split(char *str)
// {
// 	int word_num;
// 	word_num= words_count(str);

// 	int i = 0;
// 	char **res;

// 	int y_i = 0;
// 	int x_i = 0;

// 	int word_pos = 0;
// 	res = malloc(sizeof(char *) * (word_num + 1));
// 	if (!res)
// 		return NULL;
// 	while (str[i] != '\0')
// 	{
// 		while (str[i] == ' ' || str[i] == '\t')
// 			i++;

// 		word_pos = i;
// 		while (str[word_pos] != ' ' && str[word_pos] != '\t'&& str[word_pos] != '\0')
// 			word_pos++;
// 		res[y_i] = malloc(sizeof(char) * (word_pos - i + 1));
// 		while (i < word_pos)
// 		{
// 			res[y_i][x_i] = str[i];
// 			x_i++;
// 			i++;
// 		}
// 		res[y_i][x_i] = '\0';
// 		y_i++;
// 		x_i = 0;
// 	}
// 	res[y_i] = NULL;
// 	return (res);
// }

// int main(void) {
//     char *str = "apple banana pear cherry"; 
//     char **words = ft_split(str); 

//     for (int i = 0; words[i] != NULL; i++) {
//         printf("Word %d: %s\n", i + 1, words[i]);
//     }

//     for (int i = 0; words[i] != NULL; i++) {
//         free(words[i]);
//     }
//     free(words);

//     return 0;
// }