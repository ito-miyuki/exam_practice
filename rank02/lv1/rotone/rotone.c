/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:55:15 by mito              #+#    #+#             */
/*   Updated: 2024/01/08 10:16:05 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        while (argv[1][i] != '\0')
        {
            if (argv[1][i] == 'z')
            {
                write(1, "a", 1);
                i++;
            }
            else if (argv[1][i] == 'Z')
            {
                write(1, "A", 1);
                i++;
            }
            else if ((argv[1][i] >= 'a' &&  argv[1][i] < 'z') || (argv[1][i] >= 'A' &&  argv[1][i] < 'Z'))
            {
                char c = argv[1][i] + 1;
                write(1, &c, 1);
                i++;
            }
            else
            {
                write(1, &argv[1][i], 1);
                i++;
            }
        }
    }
    write(1, "\n", 1);
    return (0);
}

