/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <abekkali451@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:38:00 by ael-bekk          #+#    #+#             */
/*   Updated: 2021/12/15 10:18:56 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_init(t_list **a, t_list **b)
{
	*a = NULL;
	*b = NULL;
}

int	count_strings(char **splt)
{
	int	i;

	i = 0;
	while (splt && splt[i])
		i++;
	return (i);
}

int	valid_args(char **splt, int ac)
{
	int		valid;
	int		i;

	i = -1;
	while (++i < ac - 1)
	{
		valid = i;
		while (++valid < ac)
		{
			if (!ft_strcmp(splt[i], splt[valid]))
			{
				ft_mark('e');
				ft_putstr_fd(" : duplicata args\n", 2, YEL);
				return (-1);
			}
		}
	}
	valid = 1;
	while (ac--)
	{
		ft_atoi(splt[ac], &valid);
		if (!valid)
			return (0);
	}
	return (1);
}

t_list	*check_nbrs(char **splt, int ac)
{
	int		valid;
	t_list	*head;

	head = NULL;
	valid = valid_args(splt, ac);
	if (!valid)
	{
		ft_mark('e');
		ft_putstr_fd(" : Wrong args\n", 2, YEL);
	}
	else if (valid == 1)
		while (ac--)
			ft_lstadd_front(&head, ft_lstnew(ft_atoi(splt[ac], &valid)));
	return (head);
}

void	check_stacks(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;

	tmp = *head_a;
	if (*head_b)
	{
		ft_mark('x');
		ft_putstr_fd(" : stack b is not emty\n", 1, YEL);
	}
	else
	{
		while (tmp->next)
		{
			if (tmp->val > tmp->next->val)
			{
				ft_mark('x');
				ft_putstr_fd(" : stack a is not sorted properly\n", 1, YEL);
				return ;
			}
			tmp = tmp->next;
		}
		ft_mark('v');
	}
}
