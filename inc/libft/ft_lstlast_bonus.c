/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:10:36 by ael-bekk          #+#    #+#             */
/*   Updated: 2021/12/14 16:43:05 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *head, int rm)
{
	t_list	*tmp;

	if (!head || !head->next)
		return (head);
	if (rm && !head->next->next)
	{
		tmp = head->next;
		head->next = NULL;
		return (tmp);
	}
	return (ft_lstlast(head->next, rm));
}
