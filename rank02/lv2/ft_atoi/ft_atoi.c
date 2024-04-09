// the answer
int ft_atoi(const char *str)
{
    int res = 0;
    int sign = 1;

    while (*str == ' ' || (*str >= 9 && *str <= 13)) // スペースとその他の変なやつ飛ばす
        str++;
    if (*str == '-' || *str == '+') //マイナス記号チェック
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9') //数字が続いてる間だけのループ
    {
        res = res * 10 + *str - '0';
        str++;
    }   
    return (sign * res);
}

//refactor
int ft_atoi(const char *str)
{
    int i = 0;
    int res = 0;
    int negative = 1;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-')
    {
        negative = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - '0';
        i++;
    }
    return (res * negative);
}

//other solution
int	ft_atoi(const char *str)
{
	int i = 0;
	int res = 0;
	int neg = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * neg);
}