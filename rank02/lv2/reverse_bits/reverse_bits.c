//覚えて

unsigned char	reverse_bits(unsigned char octet)
{
	int				idx;
	unsigned char	reversed;

	idx = 8;
	reversed = 0; // reversedを0で初期化
	while (idx--)
	{
		reversed = (reversed << 1) | (octet & 1); // reversedを左にシフトして現在の最下位ビットを追加
		octet >>= 1; // octetを右にシフトして次のビットを準備
	}
	return (reversed);
}