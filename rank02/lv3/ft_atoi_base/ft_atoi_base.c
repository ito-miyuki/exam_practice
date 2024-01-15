#include <stdio.h>

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}

int	in(char c, char *base, int id)
{
	int	i;

	i = 0;
	while (base[i] != '\0' && i < id)
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	idx;
	int	sign;
	int	result;

	idx = 0;
	sign = 1;
	result = 0;
	if (str[idx] == '-')
	{
		sign = -1;
		idx++;
	}
	while (str[idx] != '\0' && in(ft_tolower(str[idx]), "0123456789abcdef", str_base))
	{
		result *= str_base;
		if (str[idx] >= '0' && str[idx] <= '9')
			result += str[idx] - '0';
		else if (str[idx] >= 'A' && str[idx] <= 'Z')
			result += str[idx] - '7';
		else if (str[idx] >= 'a' && str[idx] <= 'z')
			result += str[idx] - 'W';
		idx++;
	}
	return (result * sign);
}
/*
int main()
{
    const char *str = "Ceci permet de decouvrir le fonctionnement de ton ft_atoi_base.";
    int str_base = 16;

    int result = ft_atoi_base(str, str_base);
    printf("Converted value of '%s' in base %d is %d\n", str, str_base, result);

    return 0;
}

#include <stdio.h>

int ft_atoi_base(const char *str, int str_base)
{
    int idx = 0;
    int sign = 1;
    int result = 0;

    // 基数が有効な範囲内にあるか確認
    if (str_base < 2 || str_base > 16)
    {
        return 0;  // 基数が無効な場合は0を返す
    }

    if (str[idx] == '-')
    {
        sign = -1;
        idx++;
    }

    while (str[idx])
    {
        char c = str[idx];

        result *= str_base;

        if (c >= '0' && c <= '9')
        {
            result += c - '0';
        }
        else if (c >= 'A' && c <= 'F')
        {
            result += c - 'A' + 10;
        }
        else if (c >= 'a' && c <= 'f')
        {
            result += c - 'a' + 10;
        }
        else
        {
            // 無効な文字が含まれている場合は0を返す
            return 0;
        }

        // 基数を超える文字が含まれているかチェック
        if ((c >= '0' && c < '0' + str_base) ||
            (c >= 'A' && c < 'A' + str_base - 10) ||
            (c >= 'a' && c < 'a' + str_base - 10))
        {
            idx++;
        }
        else
        {
            // 基数を超える文字が含まれている場合は0を返す
            return 0;
        }
    }

    return result * sign;
}

int main()
{
    const char *str = "12fdb3";
    int str_base = 16;

    int result = ft_atoi_base(str, str_base);
    printf("Converted value of '%s' in base %d is %d\n", str, str_base, result);

    return 0;
}
*/