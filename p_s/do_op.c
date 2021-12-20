/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <abekkali451@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:06:28 by ael-bekk          #+#    #+#             */
/*   Updated: 2021/12/20 13:11:28 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	s(t_list **a, t_list **b, char c)
{
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
	if (c == 's' || c == 'a')
		ft_swap(a);
	if (c == 's' || c == 'b')
		ft_swap(b);
}

void	p(t_list **a, t_list **b, char c)
{
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
	if (c == 'a')
		ft_push(a, b);
	if (c == 'b')
		ft_push(b, a);
}

void	r_rr(char c, char r, int nb)
{
	while (nb-- > 0)
	{
		write(1, "r", 1);
		if (r == 'r')
			write(1, "r", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

int	move_to_top(t_list **a, int val, char c)
{
	int	size;
	int	lent_of_list;

	lent_of_list = ft_lstsize(*a);
	size = 0;
	*a = find_node(*a, val, &size);
	if (size && size * 2 >= lent_of_list)
		r_rr(c, 'r', lent_of_list - size);
	else if (size)
		r_rr(c, 'a', size);
	return ((lent_of_list - size - 1) * (size != 0));
}
