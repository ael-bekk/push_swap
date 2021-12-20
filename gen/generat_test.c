/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generat_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <abekkali451@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:16:52 by ael-bekk          #+#    #+#             */
/*   Updated: 2021/12/19 17:07:21 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	aff_mess(int ac)
{
	if (ac < 3)
		ft_putstr_fd("few args\n", 2, YEL);
	if (ac > 3)
		ft_putstr_fd("to many args\n", 2, YEL);
}

int	size_of_genfile(void)
{
	int		size;
	int		fd;
	char	c;

	fd = open("gen_rand.txt", O_RDONLY);
	size = 0;
	while (read(fd, &c, 1))
		size++;
	close(fd);
	return (size);
}

int	rand_exist(char *rand)
{
	int		size;
	int		fd;
	char	*s;

	fd = open("gen_rand.txt", O_RDONLY);
	size = size_of_genfile();
	s = (char *)malloc(size + 1);
	read(fd, s, size);
	close(fd);
	if (ft_strnstr(s, rand, size))
	{
		free(s);
		return (1);
	}
	free(s);
	close(fd);
	return (0);
}

void	generat_random(int fd, int size, int max)
{
	int		signe;
	char	*random;

	while (size > 0)
	{
		signe = !(rand() % 2) * 1 + (rand() % 2 != 0) * -1;
		random = ft_itoa((rand() % max) * signe);
		if (!rand_exist(random) && size--)
		{
			write(fd, random, ft_strlen(random));
			write(fd, " ", 1);
		}
		free(random);
	}
}

int	main(int ac, char **av)
{
	int	fd;
	int	max;
	int	size;
	int	carv;

	fd = open("gen_rand.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	aff_mess(ac);
	if (ac == 3)
	{
		max = ft_atoi(av[2], &carv);
		size = ft_atoi(av[1], &carv);
		if (size >= 0 && max * 2 >= size)
		{
			srand(time(NULL));
			generat_random(fd, size, max);
		}
		else
			ft_putstr_fd("wrong SIZE or RANG\n", 2, RED);
	}
	close(fd);
	return (0);
}
