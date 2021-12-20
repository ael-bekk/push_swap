/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_4_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <abekkali451@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:04:03 by ael-bekk          #+#    #+#             */
/*   Updated: 2021/12/19 16:51:09 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	aff_r(t_list **lst, char t, char ab)
{
	if (t == 'r')
	{
		r_rr(ab, 'r', 1);
		ft_reverse_rotate(lst);
	}
	else
	{
		r_rr(ab, 'a', 1);
		ft_rotate(lst);
	}
}

void	sort_tree(t_list **lst, char ab)
{
	int	a;
	int	b;
	int	c;

	a = (*lst)->val;
	b = (*lst)->next->val;
	c = (*lst)->next->next->val;
	if (a < b && a < c && b > c)
	{
		s(lst, NULL, ab);
		aff_r(lst, 'a', ab);
	}
	else if (a > b && a < c && b < c)
		s(lst, NULL, ab);
	else if (a < b && a > c && b > c)
		aff_r(lst, 'r', ab);
	else if (a > b && a > c && b < c)
		aff_r(lst, 'a', ab);
	else
	{
		s(lst, NULL, ab);
		aff_r(lst, 'r', ab);
	}
}

void	sort_five(t_list **a, t_list **b)
{
	move_to_top(a, 0, 'a');
	p(a, b, 'b');
	move_to_top(a, 1, 'a');
	p(a, b, 'b');
	if (is_not_sorted(*a))
		sort_tree(a, 'a');
	p(a, b, 'a');
	p(a, b, 'a');
}
