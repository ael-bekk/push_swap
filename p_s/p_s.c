/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <abekkali451@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:09:51 by ael-bekk          #+#    #+#             */
/*   Updated: 2021/12/15 10:14:54 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort(t_list **a, t_list **b, int ac)
{
	if (!is_not_sorted(*a))
		return ;
	if (ac == 2)
		s(a, b, 'a');
	else if (ac == 3)
		sort_tree(a);
	else if (ac == 5)
		sort_five(a, b);
	/*else if (ac == 100)
		sort_hundred(a, b);
	else if (ac == 500)
		//shanks_sort();
	*/else
		radix_sort(a, b);
}

int main(int ac, char **av)
{
	int		f;
	char	**split;
	t_list	*head_a;
	t_list	*head_b;

	ft_init(&head_a, &head_b);
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		split = ft_split(av[1], ' ');
		ac = count_strings(split) + 1;
		f = 1;
	}
	else
		split = &av[1];
	head_a = check_nbrs2(split, ac - 1);
	if (head_a)
		ft_sort(&head_a, &head_b, ac - 1);
	return (0);
}
