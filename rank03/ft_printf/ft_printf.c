// it passed exam simulator
#include <stdarg.h> // For va_lis, va_start, va_arg, va_copy, va_end
#include <unistd.h> // For malloc, free, write

void	put_str(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void	put_digit(long long int nbr, int base, int *len)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (nbr < 0)
	{
		nbr *= -1;
		*len += write(1, "-", 1);
	}
	if (nbr >= base)
		put_digit((nbr / base), base, len);
	*len += write(1, &hexa[nbr % base], 1);
}

int	ft_printf(const char *format, ...)
{
	int			len;
	va_list		ptr;

	len = 0;
	va_start(ptr, format);
	while (*format)
	{
		if ((*format == '%') && *(format + 1))
		{
			format++;
			if (*format == 's')
				put_str(va_arg(ptr, char *), &len);
			else if (*format == 'd')
				put_digit((long long int)va_arg(ptr, int), 10, &len);
			else if (*format == 'x')
				put_digit((long long int)va_arg(ptr, unsigned int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	return (va_end(ptr), len);
}
/// practice below

void	put_digit(long long int nbr, int base, int *len)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (nbr < 0)
	{
		nbr *= -1;
		*len += write(1, "-", 1);
	}
	if (nbr >= base)
		put_digit((nbr / base), base, len);
	*len += write(1, &hexa[nbr % base], 1);
}

void	put_digit(long long int nbr, int base, int *len)
{
	char *hex;

	hex = "0123456789abcdef";
	if (nbr < 0) //マイナス数字だったら
	{
		nbr *= -1; //数値をプラスに変換
		*len += write(1, "-", 1); //マイナス記号を書く
	}
	 if (nbr >= base) // nbrがbaseの数字より大きいなら
	 	put_digit((nbr / base), base, len); //上位の桁から処理するための再帰呼び出し
	*len += write(1, &hex[nbr % base], 1); // 数字を書いていく
}

void	put_str(char *str, int *len)
{
	if(!str)
		str = "(null)";
	while (*str)
	{
		*len += write(1, str, 1);
		str++;
	}
}

int ft_printf(const char *format, ... )
{
	int len = 0;
	va_list ptr;

	va_start(ptr, format);
	while (*format) // format(string)を最後までスキャンする
	{
		if ((*format == '%') && *(format + 1)) //format strが％マークで、その次の文字が存在するなら
		{
			format++; //次の文字に移って
			if (*format == 's') // sならput_str
				put_str(va_arg(ptr, char *), &len);
			else if (*format == 'd') // dならput_digitを10進数で呼ぶ
				put_digit((long long int)va_arg(ptr, int), 10, &len);
			else if (*format == 'x') // xならput_digitを16進数で呼ぶ（ヘキサ）
				put_digit((long long int)va_arg(ptr, unsigned int), 16, &len);
		}
		else //それ以外ならただその文字を出力する
			len += write(1, format, 1); //printfは出文字の合計を返すからlenに貯めていく
		format++; //次の文字に行く
	}
	va_end(ptr);
	return (len);
}

// #include <stdio.h>

// int main()
// {
// 	const char *str = "hello";
// 	int d = 88;
// 	int x = 88;
// 	int res = printf("printf is: %s and %d and %x\n", str, d, x);
// 	int res2 = ft_printf("printf is: %s and %d and %x\n", str, d, x);
// 	// printf("printf is: %s and %d and %x\n", str, d, x);
// 	// ft_printf("ft_printf is: %s and %d and %x\n", str, d, x);
// 	printf("printf's return value is %d\n", res);
// 	printf("printf's return value is %d\n", res2);
// 	return (0);
// }