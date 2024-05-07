#include <unistd.h>
#include <stdarg.h>

void	put_str(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		*len += write(1, str, 1);
		str++;
	}
}

void	put_digit(long long int nbr, int base, int *len)
{
	char *hex = "0123456789abcdef";

	if (nbr < 0)
	{
		nbr *= -1;
		*len += write(1, "-", 1);
	}
	if (nbr >= base)
		put_digit((nbr / base), base, len);
	*len += write(1, &hex[nbr % base], 1);
}

int ft_printf(const char *format, ... )
{
	int len = 0;
	va_list ptr;

	va_start(ptr, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == 's')
				put_str(va_arg(ptr, char *), &len);
			else if (*format == 'd')
				put_digit((long long)va_arg(ptr, int), 10,  &len);
			else if (*format == 'x')
				put_digit((long long)va_arg(ptr, unsigned int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(ptr);
	return (len);
}

#include <stdio.h>

int main()
{
	const char *str = "hello";
	int d = 88;
	int x = 88;
	int res = printf("printf is: %s and %d and %x\n", str, d, x);
	int res2 = ft_printf("printf is: %s and %d and %x\n", str, d, x);
	printf("printf's return value is %d\n", res);
	printf("printf's return value is %d\n", res2);
	return (0);
}