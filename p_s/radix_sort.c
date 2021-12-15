/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <abekkali451@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:36:14 by ael-bekk          #+#    #+#             */
/*   Updated: 2021/12/15 10:15:24 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_not_sorted(t_list *a)
{
	while (a && a->next)
	{
		if (a->val > a->next->val)
			return (true);
		a = a->next;
	}
	return (false);
}

int	bit_shift(t_list *a)
{
	int	valid;

	valid = false;
	while (a)
	{
		a->val >>= 1;
		if (a->val)
            valid = true;
		a = a->next;
	}
	return (valid);
}

void	a_to_b(t_list **a, t_list **b)
{
	int		ret;

	ret = ft_lstsize(*a);
	while (ret--)
	{
		if ((*a)->val % 2)
		{
			r_rr('a', 'a', 1);
			ft_rotate(a);
		}
		else
			p(a, b, 'b');
	}
}

void	radix_sort(t_list **a, t_list **b)
{
	int		valid;

	valid = true;
	while (valid)
	{
		if (is_not_sorted(*a) == false)
			return ;
		a_to_b(a, b);
		while (*b)
			p(a, b, 'a');
		valid = bit_shift(*a);
	}
}
