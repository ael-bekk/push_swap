/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joine_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <abekkali451@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:42:47 by ael-bekk          #+#    #+#             */
/*   Updated: 2021/12/19 15:44:17 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*join_args(char **s, int ac)
{
	char	*join;
	char	*res;
	int		i;

	join = (char *)malloc(1);
	join[0] = 0;
	i = -1;
	while (++i < ac)
	{
		res = join;
		join = ft_strjoin(res, s[i]);
		free(res);
		res = join;
		join = ft_strjoin(res, " ");
		free(res);
	}
	return (join);
}
