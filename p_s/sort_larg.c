/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_larg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:13:17 by ael-bekk          #+#    #+#             */
/*   Updated: 2021/12/19 14:27:07 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	move_100_a_b(t_list **a, t_list **b)
{
	int		div;
	char	c;

	div = 10;
	while (*a)
	{
		c = best_move(*a, div, 1, 0);
		while (best_move(*a, div, 1, 0) != -1)
		{
			c = best_move(*a, div, 1, 0);
			if ((*a)->val < div)
				p(a, b, 'b');
			else
				r(a, 'a', c);
		}
		div += 10;
	}
}

static void	move_100_b_a(t_list **a, t_list **b)
{
	int	index;

	index = 500;
	while (--index >= 0)
	{
		move_to_top(b, index, 'b');
		p(a, b, 'a');
	}
}

static void	move_fh_a_b(t_list **a, t_list **b)
{
	int		div;
	char	c;

	div = 250;
	while (div < 500)
	{
		c = best_move(*a, div, 1, 0);
		while (best_move(*a, div, 1, 0) != -1)
		{
			c = best_move(*a, div, 1, 0);
			if ((*a)->val < div)
				p(a, b, 'b');
			else
				r(a, 'a', c);
		}
		div += 100;
	}
}

static void	move_fh_b_a(t_list **a, t_list **b)
{
	int		div;
	char	c;

	div = 500;
	while (div >= 0)
	{
		c = best_move(*b, div, 0, 1);
		while (best_move(*b, div, 0, 1) != -1)
		{
			c = best_move(*b, div, 0, 1);
			if ((*b)->val > div)
				p(a, b, 'a');
			else
				r(b, 'b', c);
		}
		div -= 50;
	}
}

void	sort_five_hund(t_list **a, t_list **b)
{
	move_fh_a_b(a, b);
	move_fh_b_a(a, b);
	move_100_a_b(a, b);
	move_100_b_a(a, b);
}
