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
