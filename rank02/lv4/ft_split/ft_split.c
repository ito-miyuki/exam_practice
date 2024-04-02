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
	printf("%d\n", counter);
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
	printf("%d\n", word_len);
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
    char *str = "  starting and ending   "; 
    char **words = ft_split(str); 

    for (int i = 0; words[i]; i++) {
        printf("Word %d: %s\n", i + 1, words[i]);
    }

    for (int i = 0; words[i]; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}


//other solution

// char *ft_strncpy(char *s1, char *s2, int n)
// {
// 	int i = -1;

// 	while (++i < n && s2[i])
// 		s1[i] = s2[i];
// 	s1[i] = '\0';
// 	return (s1);
// }

// char	**ft_split(char *str)
// {
// 	int i = 0;
// 	int j = 0;
// 	int k = 0;
// 	int wc = 0;
// 	while (str[i])
// 	{
// 		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
// 			i++;
// 		if (str[i])
// 			wc++;
// 		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
// 			i++;
// 	}
// 	char **out = (char **)malloc(sizeof(char *) * (wc + 1));
// 	i = 0;
// 	while (str[i])
// 	{
// 		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
// 			i++;
// 		j = i;
// 		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
// 			i++;
// 		if (i > j)
// 		{
// 			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
// 			ft_strncpy(out[k++], &str[j], i - j);
// 		}
// 	}
// 	out[k] = NULL;
// 	return (out);
// }
