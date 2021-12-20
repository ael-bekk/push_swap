/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hund2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <abekkali451@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:37:51 by ael-bekk          #+#    #+#             */
/*   Updated: 2021/12/19 16:51:13 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	less_than(t_list *a, int val)
{
	int	gr;

	gr = 100;
	while (a)
	{
		if (a->val < gr && a->val > val)
			gr = a->val;
		a = a->next;
	}
	return (gr);
}

void	r(t_list **lst, char ab, char r)
{
	r_rr(ab, r, 1);
	if (r == 'a')
		ft_rotate(lst);
	else
		ft_reverse_rotate(lst);
}

char	best_move(t_list *a, int div, int p, int g)
{
	int	start;
	int	end;
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(a);
	start = -1;
	end = -1;
	while (a)
	{
		if ((a->val < div) * p || (a->val > div) * g)
		{
			if (start == -1)
				start = i;
			end = i;
		}
		i++;
		a = a->next;
	}
	if (start == -1 || end == -1)
		return (-1);
	if (start > size - end)
		return ('r');
	return ('a');
}
