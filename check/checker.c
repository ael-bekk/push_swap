/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <abekkali451@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:38:50 by ael-bekk          #+#    #+#             */
/*   Updated: 2021/12/15 10:11:13 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	opp_exist(char *b)
{
	return (!ft_strcmp("sa", b) || !ft_strcmp("ss", b)
		|| !ft_strcmp("sb", b) || !ft_strcmp("pa", b)
		|| !ft_strcmp("pb", b) || !ft_strcmp("ra", b)
		|| !ft_strcmp("rr", b) || !ft_strcmp("rb", b)
		|| !ft_strcmp("rra", b) || !ft_strcmp("rrr", b)
		|| !ft_strcmp("rrb", b));
}

void	do_opers(t_list **head_a, t_list **head_b, char *b, int *i)
{
	if (b[0])
	{
		if (opp_exist(b))
		{
			if (!ft_strcmp("sa", b) || !ft_strcmp("ss", b))
				ft_swap(head_a);
			if (!ft_strcmp("sb", b) || !ft_strcmp("ss", b))
				ft_swap(head_a);
			if (!ft_strcmp("pa", b))
				ft_push(head_a, head_b);
			if (!ft_strcmp("pb", b))
				ft_push(head_b, head_a);
			if (!ft_strcmp("ra", b) || !ft_strcmp("rr", b))
				ft_rotate(head_a);
			if (!ft_strcmp("rb", b) || !ft_strcmp("rr", b))
				ft_rotate(head_b);
			if (!ft_strcmp("rra", b) || !ft_strcmp("rrr", b))
				ft_reverse_rotate(head_a);
			if (!ft_strcmp("rrb", b) || !ft_strcmp("rrr", b))
				ft_reverse_rotate(head_b);
		}
		else
			*i = 4;
	}
}

void	check_opers(t_list **head_a, t_list **head_b)
{
	int		i;
	char	b[4];
	char	c;

	i = 0;
	while (read(0, &c, 1))
	{
		b[i++] = c * (c != '\n');
		if (c == '\n')
		{
			i = 0;
			do_opers(head_a, head_b, b, &i);
		}
		if (i == 4)
		{
			ft_mark('e');
			ft_putstr_fd(" : Wrong Operation\n", 2, YEL);
			while (c != '\n' && read(0, &c, 1))
				;
			return ;
		}
	}
	check_stacks(head_a, head_b);
}

int	main(int ac, char **av)
{
	int		f;
	char	**splt;
	t_list	*head_a;
	t_list	*head_b;

	ft_init(&head_a, &head_b);
	f = 0;
	splt = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		splt = ft_split(av[1], ' ');
		ac = count_strings(splt) + 1;
		f = 1;
	}
	else
		splt = &av[1];
	head_a = check_nbrs(splt, ac - 1);
	if (head_a)
		check_opers(&head_a, &head_b);
	return (0);
}
