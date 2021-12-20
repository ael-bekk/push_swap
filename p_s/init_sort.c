/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <abekkali451@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:04:58 by ael-bekk          #+#    #+#             */
/*   Updated: 2021/12/19 14:07:23 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_nb(int *arr, int size, int nb)
{
	int	i;

	i = -1;
	while (++i < size)
		if (arr[i] == nb)
			return (i);
	return (0);
}

int	*sort_arr(char **splt, int ac)
{
	int	i;
	int	j;
	int	tmp;
	int	*arr;

	i = -1;
	arr = (int *)malloc(sizeof(int) * ac);
	while (arr && ++i < ac)
		arr[i] = ft_atoi(splt[i], &tmp);
	i = -1;
	while (arr && ++i < ac - 1)
	{
		j = i;
		tmp = i;
		while (++j < ac)
			if (arr[j] < arr[tmp])
				tmp = j;
		if (tmp != i)
		{
			j = arr[tmp];
			arr[tmp] = arr[i];
			arr[i] = j;
		}
	}
	return (arr);
}

int	*init_arr(char **splt, int ac)
{
	int	tmp;
	int	i;
	int	*arr;
	int	*arr_sorted;

	arr_sorted = sort_arr(splt, ac);
	if (!arr_sorted)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * ac);
	i = -1;
	while (arr && ++i < ac)
		arr[i] = find_nb(arr_sorted, ac, ft_atoi(splt[i], &tmp));
	free(arr_sorted);
	return (arr);
}

t_list	*check_nbrs2(char **splt, int ac)
{
	int		valid;
	int		*arr;
	t_list	*head;

	head = NULL;
	valid = valid_args(splt, ac);
	if (!valid)
	{
		ft_mark('e');
		ft_putstr_fd(" : Wrong args\n", 2, YEL);
	}
	else if (valid == 1)
	{
		arr = init_arr(splt, ac);
		while (arr && ac--)
			ft_lstadd_front(&head, ft_lstnew(arr[ac]));
		free(arr);
	}
	return (head);
}
