//覚えて！
void	print_bits(unsigned char octet)
{
	int				idx;
	unsigned char	bit;

	idx = 8;
	while (idx--)
	{
		bit = ((octet >> idx & 1) + '0'); //octetをiだけ右にシフト　&１をして　'0'を足して文字にする
		write(1, &bit, 1);
	}
}

void	print_bits(unsigned char octet)
{
	int i = 8;
	unsigned char bit;

	while (i--)
	{
		bit = ((octet >> i & 1) + '0');
		write(1, &bit, 1);
	}
}

// other solution
void	print_bits(unsigned char octet)
{
	int	bit;
	char c;

	bit = 128;
	while (bit > 0)
	{
		if (octet < bit)
		{
			c = '0';
			bit = bit / 2;
			write(1, &c, 1);
		}
		else
		{
			c = '1';
			write(1, &c, 1);
			octet = octet - bit;
			bit = bit / 2;
		}
	}
}
