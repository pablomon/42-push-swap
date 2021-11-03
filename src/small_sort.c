/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:37:49 by pmontese          #+#    #+#             */
/*   Updated: 2021/11/01 15:15:09 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_val(t_list *lst, int val)
{
	int	pos;
	int	v;

	pos = 0;
	while (lst)
	{
		v = *(int *)lst->content;
		if (v == val)
			return (pos);
		lst = lst->next;
		pos++;
	}
	return (-1);
}

int	smallsort_is_progression(t_data ss)
{
	int	(*move)(t_data);

	if (is_progression(ss.a->lst))
	{
		move = &shiftdowna;
		if (is_sorted(ss.a->lst))
			move = &pushb2a;
		*ss.moves += domove(move, ss);
		return (1);
	}
	return (0);
}

void	smallsort(t_data ss, int len)
{
	int	min;
	int	(*move)(t_data);

	min = 0;
	while (!is_sorted(ss.a->lst) || ft_lstsize(ss.b->lst) != 0)
	{
		move = &shiftupa;
		if (smallsort_is_progression(ss))
			continue ;
		if (ft_lstsize(ss.a->lst) > 3 && find_val(ss.a->lst, min) > len / 2)
			move = &shiftdowna;
		if (ft_lstsize(ss.a->lst) > 3 && val(ss.a->lst, 0) == min)
		{
			move = &pusha2b;
			min++;
		}
		if (ft_lstsize(ss.a->lst) < 4 && val(ss.a->lst, 0) <= val(ss.a->lst, 2))
			move = &shiftdowna;
		if (ft_lstsize(ss.a->lst) < 4 && val(ss.a->lst, 0) > val(ss.a->lst, 1))
			move = &swapa;
		*ss.moves += domove(move, ss);
	}
}
