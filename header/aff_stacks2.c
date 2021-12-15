/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_stacks2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <abekkali451@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:42:10 by ael-bekk          #+#    #+#             */
/*   Updated: 2021/12/15 10:13:33 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_mark(char m)
{
	if (m == 'v')
		ft_putstr_fd("\u2714 OK\n", 1, GRN);
	if (m == 'x')
		ft_putstr_fd("\u274c ", 1, RED);
	if (m == 'e')
		ft_putstr_fd("Error", 2, RED);
}

void	ft_init_s(char x)
{
	write(1, "\t\t", 2);
	affich_char(x);
	affich_char(x);
	if (x == 'v')
	{
		affich_char(x);
		write(1, " : ", 4);
		affich_char(x);
		affich_char(x);
		affich_char('a');
		write(1, " + ", 3);
		affich_char(x);
		affich_char(x);
		affich_char('b');
		write(1, "\n", 1);
		return ;
	}
	write(1, "  : ", 4);
	affich_char(x);
	affich_char('a');
	write(1, " + ", 3);
	affich_char(x);
	affich_char('b');
	write(1, "\n", 1);
}

void	ft_init_b(void)
{
	char	ab[6];
	int		i;
	int		j;

	ab[0] = 'a';
	ab[1] = 'b';
	ab[2] = 's';
	ab[3] = 'p';
	ab[4] = 'r';
	ab[5] = 'v';
	i = -1;
	j = 0;
	while (++i < 8)
	{
		generate();
		dictionnaire(ab[j % 4 + 2], ab[i % 2]);
		j += i % 2;
	}
	generate();
	ft_init_s('s');
}
