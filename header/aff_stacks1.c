/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_stacks1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <abekkali451@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:41:49 by ael-bekk          #+#    #+#             */
/*   Updated: 2021/12/19 16:46:15 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	affich_char(char x)
{
	if (x == 'a')
		write(1, RED, 5);
	else if (x == 'b')
		write(1, YEL, 5);
	else
		write(1, MAG, 5);
	if (x != 'v')
		write(1, &x, 1);
	else
		write(1, "r", 1);
}

void	affich_line_blue(void)
{
	int	t;

	write(1, BLU, 5);
	t = 0;
	while (t++ < 130)
		write(1, "-", 1);
	write(1, "\n", 1);
}

void	dictionnaire(char o, char x)
{
	write(1, "\t\t", 2);
	if (o == 'v')
	{
		affich_char('r');
		affich_char('r');
	}
	else
		affich_char(o);
	affich_char(x);
	write(1, MAG, 5);
	if (o == 's')
		write(1, "  : swap", 9);
	if (o == 'p')
		write(1, "  : push", 9);
	if (o == 'r')
		write(1, "  : rotate", 11);
	if (o == 'v')
		write(1, " : reverse rotate", 17);
	write(1, " ", 1);
	affich_char(x);
}

void	generate(void)
{
	write(1, "\n", 1);
	write(1, RED, 5);
	write(1, "\t\t|     |", 10);
	write(1, YEL, 5);
	write(1, "\t\t\t\t|     |", 11);
}

int	aff_header(void)
{
	int		fd;
	char	c;

	fd = open("header/name_p", O_RDWR);
	while (read(fd, &c, 1) > 0)
		affich_char(c);
	write(1, "\n", 1);
	affich_line_blue();
	ft_init_b();
	write(1, RED, 5);
	write(1, "\t\t-------", 9);
	write(1, YEL, 5);
	write(1, "\t\t\t\t-------", 11);
	ft_init_s('r');
	write(1, RED, 5);
	write(1, "\t\tStack a", 9);
	write(1, YEL, 5);
	write(1, "\t\t\t\tStack b", 11);
	ft_init_s('v');
	affich_line_blue();
	return (0);
}
