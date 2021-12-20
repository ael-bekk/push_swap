/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_p_r_rr_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <abekkali451@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:17:46 by ael-bekk          #+#    #+#             */
/*   Updated: 2021/12/19 14:08:34 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_list	*find_node(t_list *head, int val, int *size)
{
	t_list	*tmp;
	t_list	*res;

	if (!head || !head->next || head->val == val)
		return (head);
	tmp = head;
	while (tmp->next)
	{
		*size = *size + 1;
		if (tmp->next->val == val)
		{
			res = tmp->next;
			tmp->next = NULL;
			ft_lstlast(res, 0)->next = head;
			return (res);
		}
		tmp = tmp->next;
	}
	return (tmp);
}

void	ft_swap(t_list **head)
{
	t_list	*tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = (*head)->next;
	(*head)->next = (*head)->next->next;
	tmp->next = *head;
	*head = tmp;
}

void	ft_push(t_list **head1, t_list **head2)
{
	t_list	*tmp;

	tmp = NULL;
	if (!*head2)
		return ;
	if (*head1)
		tmp = *head1;
	*head1 = *head2;
	*head2 = (*head2)->next;
	(*head1)->next = tmp;
}

void	ft_rotate(t_list **head)
{
	t_list	*tmp;

	if (!(*head) || !(*head)->next)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = NULL;
	ft_lstadd_back(head, tmp);
}

void	ft_reverse_rotate(t_list **head)
{
	t_list	*tmp;

	if (!(*head) || !(*head)->next)
		return ;
	tmp = ft_lstlast(*head, 1);
	tmp->next = *head;
	*head = tmp;
}
