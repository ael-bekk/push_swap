/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:47:57 by ael-bekk          #+#    #+#             */
/*   Updated: 2021/12/11 14:15:45 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str, int *valid)
{
	int				ng;
	unsigned int	n;

	n = 0;
	ng = 1;
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	if (*str == '-')
		ng = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		n = n * 10 + (*str - '0');
		str++;
		if ((n > INT_MAX && ng > 0) || (n > (unsigned )(INT_MAX) + 1 && ng < 0))
			*valid = 0;
	}
	while (*str && *str == ' ')
		str++;
	*valid = *valid * !*str;
	return (n * ng);
}
