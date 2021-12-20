/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <abekkali451@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:36:14 by ael-bekk          #+#    #+#             */
/*   Updated: 2021/12/19 14:08:09 by ael-bekk         ###   ########.fr       */
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

int	enough(t_list *a)
{
	while (a && a->val % 2 == 0)
		a = a->next;
	while (a && a->val % 2 == 1)
		a = a->next;
	return (a == NULL);
}

void	a_to_b(t_list **a, t_list **b, int valid)
{
	int	ret;

	ret = ft_lstsize(*a);
	while (ret-- && is_not_sorted(*a))
	{
		if ((*a)->val % 2)
		{
			r_rr('a', 'a', 1);
			ft_rotate(a);
		}
		else
			p(a, b, 'b');
		if (valid && enough(*a))
			ret = 0;
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
		if (!enough(*a))
		{
			a_to_b(a, b, ft_lstlast(*a, 0)->val % 2 == 0);
			while (*b)
				p(a, b, 'a');
		}
		valid = bit_shift(*a);
	}
}
