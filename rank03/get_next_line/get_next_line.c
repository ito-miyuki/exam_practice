#include "get_next_line.h"

// 指定した文字が最初に出現するポインタを返す関数
static char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

// 文字列の長さを返す関数
static size_t	ft_strlen(const char *s)
{
	size_t	i = 0;
	
	while (s[i])
		i++;
	return (i);
}

// 一つの文字列を別の文字列にコピーする関数
static void	ft_strcpy(char *dst, const char *src)
{
	while (*src)	
		*dst++ = *src++;
	*dst = '\0';
}

// 文字列を複製して新しいメモリを割り当てる関数
static char	*ft_strdup(const char *src)
{
	size_t	len = ft_strlen(src) + 1;
	char	*dst = malloc(len);
	
	if (dst == NULL)
		return (NULL);
	ft_strcpy(dst, src);
	return (dst);
}

// 二つの文字列を連結して新しいメモリを割り当てる関数
static char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	s1_len = ft_strlen(s1);
	size_t	s2_len = ft_strlen(s2);
	char	*join = malloc((s1_len + s2_len + 1));

	if (!s1 || !s2)
		return (NULL);
	if (!join)
		return (NULL);
	ft_strcpy(join, s1);
	ft_strcpy((join + s1_len), s2);
	free(s1);
	return (join);
}

// ファイルディスクリプタから次の行を読み取る関数
char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];  // 読み込みデータを一時保存する静的バッファ
	char		*line;
	char		*newline;
	int			countread;
	int			to_copy;

	line = ft_strdup(buf);  // バッファの内容をlineにコピー
	while (!(newline = ft_strchr(line, '\n')) && (countread = read(fd, buf, BUFFER_SIZE)))  // 改行が見つかるまで読み込み
	{
		buf[countread] = '\0';  // 終端文字を設定
		line = ft_strjoin(line, buf);  // 読み込んだデータをlineに追加
	}
	if (ft_strlen(line) == 0)  // lineが空ならメモリを解放してNULLを返す
		return (free(line), NULL);

	if (newline != NULL)  // 改行が見つかった場合
	{
		to_copy = newline - line + 1;
		ft_strcpy(buf, newline + 1);  // 改行後の文字をバッファにコピー
	}
	else  // ファイルの終わりに到達した場合
	{
		to_copy = ft_strlen(line);
		buf[0] = '\0';  // バッファを空にする
	}
	line[to_copy] = '\0';  // 終端文字を設定
	return (line);
}

// テスト用メイン関数
#include "get_next_line.h"
#include <stdio.h>  // 標準入出力のためのヘッダ
#include <fcntl.h>  // ファイル制御のためのヘッダ
#include <unistd.h> // Unix標準のためのヘッダ

int main(void)
{
    char *line;
    int fd = 0;

    fd = open("example.txt", O_RDONLY);  // ファイルを読み取り専用でオープン

        while ((line = get_next_line(fd)) != NULL) // 行がなくなるまで読み続ける
		{
			printf("%s", line);
			free(line);  // メモリリークを防ぐために、使用済みのメモリを解放
    	}

    close(fd);  // ファイルディスクリプタを閉じる

    return 0;
}