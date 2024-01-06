/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:20:01 by mito              #+#    #+#             */
/*   Updated: 2024/01/02 18:33:54 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void ft_write_num(int num)
{
	char str[10] = "0123456789";

	if (num > 9)
		ft_write_num(num / 10);
	write(1, &str[num % 10], 1);
}

int main()
{
	int i = 1;

	while (i <= 100)
	{
		if (i % 15 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_write_num(i);
		i++;
		write(1, "\n", 1);	
	}
}

