// 覚えた方がいい！
/*
lcm = 最小公倍数
たとえば、4と6の場合、4の倍数は4, 8, 12, 16, ...で、6の倍数は6, 12, 18, 24, ...。共通する倍数は 12, 24, ... だから最小公倍数は12
*/


unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int lcm;
	if (a == 0 || b == 0)
		return (0);
	if (a > b) // 最小公倍数は必ずaとbのうち大きい方以上の値になるから
		lcm = a;
	else 
		lcm = b;
	while(1) //条件が満たされるまで無限ループ
	{
		if (lcm % a == 0 && lcm % b == 0)
			return (lcm);
		lcm++;
	}
}

//練習