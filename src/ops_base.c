/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:37:33 by pmontese          #+#    #+#             */
/*   Updated: 2021/11/01 15:07:43 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	shiftdown(t_stk *stk)
{
	t_list	*snd2last;
	t_list	*last;

	if (VERBOSE == 1)
		printf("shift down %c: ", stk->id);
	last = stk->lst;
	while (last->next)
	{
		snd2last = last;
		last = last->next;
	}
	ft_lstadd_front(&(stk->lst), ft_lstnew(last->content));
	snd2last->next = NULL;
	free(last);
	if (VERBOSE == 1)
		printf("OK\n");
	return (1);
}

int	shiftup(t_stk *stk)
{
	t_list	*head;
	t_list	*snd;
	int		*fst_cnt;
	t_list	*last;

	if (VERBOSE == 1)
		printf("shift up %c: ", stk->id);
	head = stk->lst;
	snd = head->next;
	fst_cnt = head->content;
	head->content = head->next->content;
	head->next = head->next->next;
	snd->content = fst_cnt;
	last = ft_lstlast(head);
	last->next = snd;
	snd->next = NULL;
	if (VERBOSE == 1)
		printf("OK\n");
	return (1);
}

int	swap(t_stk *stk)
{
	t_list	*lst;
	void	*temp;

	if (VERBOSE == 1)
		printf("Swap %c: ", stk->id);
	lst = stk->lst;
	temp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = temp;
	if (VERBOSE == 1)
		printf("OK\n");
	return (1);
}

int	push(t_stk *from, t_stk *to)
{
	t_list	*tmp;

	if (VERBOSE == 1)
		printf("Push %c to %c (val = %d): ",
			from->id, to->id, val(from->lst, 0));
	ft_lstadd_front(&(to->lst), ft_lstnew(from->lst->content));
	tmp = from->lst;
	from->lst = from->lst->next;
	free(tmp);
	if (VERBOSE == 1)
		printf("OK\n");
	return (1);
}

int	domove(int (*function_ptr)(t_data), t_data ss)
{
	int	ret;

	ret = (*function_ptr)(ss);
	if (VERBOSE)
		printh(ss);
	return (ret);
}
