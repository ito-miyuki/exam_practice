#include <unistd.h>

// これの方がいい
// まだ後ろに文字があるか確認してからwriteを呼ぶために、flagで一旦記憶するだけ
int main(int argc, char const *argv[])
{
	int i;
	int flg;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' || argv[1][i] == '\t')
				flg = 1; //まだ後ろに文字があるか確認してからwriteを呼びたいので、flagで一旦記憶するだけ
			if (!(argv[1][i] == ' ' || argv[1][i] == '\t'))
			{
				if (flg == 1)
					write(1, " ", 1);
				flg = 0;
				write(1, &argv[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

// it can remove only one space at the end
int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

int main(int argc, char **argv)
{
    int i = 0;
    int len = ft_strlen(argv[1]);
    if (argc == 2)
    {
        while (i < len)
        {
            while (argv[1][i] == ' ' || argv[1][i] == '\t')
                i++;
            while (argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0')
            {
                write(1, &argv[1][i], 1);
                i++;
            }
            if ((argv[1][i] == ' ' || argv[1][i] == '\t') && i < len - 1)
                    write(1, " ", 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}

