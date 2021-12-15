/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:09:53 by ael-bekk          #+#    #+#             */
/*   Updated: 2021/12/10 18:31:22 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int val)
{
	t_list	*new;

	new = NULL;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->val = val;
	new->next = NULL;
	return (new);
}
