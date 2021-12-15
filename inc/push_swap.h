/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <abekkali451@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:17:27 by ael-bekk          #+#    #+#             */
/*   Updated: 2021/12/15 10:12:55 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//---------- define colors ----------//
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

# include "libft/libft.h"
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <time.h>

//---------- push swap operations ----------//
t_list  *find_node(t_list *head, int val, int *size);
void	ft_swap(t_list **head);
void	ft_push(t_list **head1, t_list **head2);
void	ft_rotate(t_list **head);
void	ft_reverse_rotate(t_list **head);

//---------- checker ----------//
int		opp_exist(char *b);
void	do_opers(t_list **head_a, t_list **head_b, char *b, int *i);
void	check_opers(t_list **head_a, t_list **head_b);

//---------- errors ----------//
void	ft_init(t_list **a, t_list **b);
int		count_strings(char **splt);
int		valid_args(char **splt, int ac);
t_list	*check_nbrs(char **splt, int ac);
void	check_stacks(t_list **head_a, t_list **head_b);

//---------- header ----------//
void	affich_char(char x);
void	affich_line_blue(void);
void	dictionnaire(char o, char x);
void	generate(void);
int		aff_header(void);
//---
void	ft_mark(char m);
void	ft_init_b(void);
void	ft_init_s(char x);

//---------- Radix sort ----------//
int		is_not_sorted(t_list *a);
int		bit_shift(t_list *a);
void	a_to_b(t_list **a, t_list **b);
void	radix_sort(t_list **a, t_list **b);

//---------- init_sort ----------//
int		find_nb(int *arr, int size, int nb);
int		*sort_arr(char **splt, int ac);
int		*init_arr(char **splt, int ac);
t_list	*check_nbrs2(char **splt, int ac);

//---------- do_op ----------//
void	s(t_list **a, t_list **b, char c);
void	p(t_list **a, t_list **b, char c);
void	r_rr(char c, char r, int nb);
int		move_to_top(t_list **a, int val, char c);

//---------- sort_3_4_5 ----------//
void	sort_tree(t_list **lst);
void	sort_five(t_list **a, t_list **b);

#endif
