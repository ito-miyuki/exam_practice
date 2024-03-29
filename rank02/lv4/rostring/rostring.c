#include <unistd.h> 

//ちょっと引っ掛けだよ！　argc > 1 でもargv[1]だけしか扱わない。メイン関数気をつけて！

#include <unistd.h>

int is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

#include <stdio.h>
void ft_rostring(char *str)
{
	int i = 0;
	int first_word = 0;

	while ((str[first_word] != '\0') && (is_space(str[first_word]) == 1)) //もし最初に空白あるなら飛ばす
		first_word++;
	i = first_word; //ここが１単語目の開始位置
	while ((str[i] != '\0') && (is_space(str[i]) == 0)) //１単語目を飛ばす。このループの後iは空白文字
		i++;
	while (str[i] != '\0')
	{
		if (is_space(str[i]) == 0 && is_space(str[i - 1]) == 1) //出力可能な文字で、一個前が空白なら
		{
			while (is_space(str[i]) == 0 && str[i] != '\0') //次の空白にぶつかるまで書く。つまり１単語書く
			{
				write(1, &str[i], 1);
				i++;
			}
			write(1, " ", 1); //単語を書き終わったら空白文字を入れる。一単語しかない時はここのifに入らないから大丈夫
		}
		i++;
	}
	while ((str[first_word] != '\0') && (is_space(str[first_word]) == 0))
	{
		write(1, &str[first_word], 1);
		first_word++;
	}
}

int main(int argc, char **argv)
{
	if (argc > 1)
		ft_rostring(argv[1]);
	write(1, "\n", 1);
}