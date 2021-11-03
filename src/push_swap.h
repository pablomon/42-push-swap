/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:44:36 by pmontese          #+#    #+#             */
/*   Updated: 2021/11/02 12:44:38 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>
# include <limits.h>
# define VERBOSE 0
# define READ_INPUT 1
# define INIT 0
# define FREE 1

typedef struct s_stk
{
	char	id;
	t_list	*lst;
}			t_stk;
typedef struct s_data
{
	t_stk	*a;
	t_stk	*b;
	 char	*ops;
	char	**p_ops;
	int		*moves;
}			t_data;

int		shiftdown(t_stk *stk);
int		shiftup(t_stk *stk);
int		swap(t_stk *stk);
int		push(t_stk *from, t_stk *to);
int		domove(int (*function_ptr)(t_data), t_data ss);
int		swapa(t_data stacks);
int		pusha2b(t_data stacks);
int		pushb2a(t_data stacks);
int		shiftupa(t_data stacks);
int		shiftdowna(t_data stacks);
void	print_lst_h(t_list *link);
void	printh(t_data stacks);
void	printv(t_data stacks);
int		val(t_list *link, int pos);
void	set_int(t_list *link, int pos, int val);
void	writeop(t_data data, const char *op);
void	sort_list(t_list *lst, int len);
void	simplify_lst(t_data *data, int len);
void	radix_short(t_data ss, int input_len);
void	smallsort(t_data ss, int len);
int		overflows(const char *str);
int		is_valid_int(const char *str);
int		is_sorted(t_list *lst);
int		is_progression(t_list *lst);
t_list	*lstdup(t_list *lst);

#endif
