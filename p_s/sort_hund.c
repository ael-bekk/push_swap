/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hund.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <abekkali451@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:33:59 by ael-bekk          #+#    #+#             */
/*   Updated: 2021/12/19 16:50:49 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	move_a_b(t_list **a, t_list **b, int size)
{
	int		div;
	int		first;
	char	c;

	first = 0;
	div = size / 10 * 6;
	while (div < size)
	{
		c = best_move(*a, div, 1, 0);
		while (best_move(*a, div, 1, 0) != -1)
		{
			if ((*a)->val < div)
				p(a, b, 'b');
			else
				r(a, 'a', c);
		}
		div += 17;
		if (div >= size - 1 && !first++)
			div = size - 2;
	}
	if ((*a)->val > (*a)->next->val)
		s(a, b, 'a');
}

void	push_a_b(t_list **a, t_list **b)
{
	if (less_than(*a, (*b)->val) != 100)
	{
		move_to_top(a, less_than(*a, (*b)->val), 'a');
		p(a, b, 'a');
	}
	else
	{
		p(a, b, 'a');
		r(a, 'a', 'a');
	}
}

void	move_b_a(t_list **a, t_list **b, int size)
{
	int		div;
	char	c;

	div = size / 10 * 4;
	while (*b)
	{
		c = best_move(*b, div, 0, 1);
		while (best_move(*b, div, 0, 1) != -1)
		{
			if ((*b)->val > div)
				push_a_b(a, b);
			else
				r(b, 'b', c);
		}
		div -= size / 6 - 1;
	}
}

void	sort_hundred(t_list **a, t_list **b)
{
	int size;

	size = ft_lstsize(*a);
	move_a_b(a, b, size);
	move_b_a(a, b, size);
	move_to_top(a, 0, 'a');
}
