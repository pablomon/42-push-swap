/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:37:42 by pmontese          #+#    #+#             */
/*   Updated: 2021/11/01 13:38:18 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst_h(t_list *link)
{
	while (link)
	{
		if (link->content != NULL)
			printf("%3d", *(int *)(link->content));
		link = link->next;
		if (link)
			printf(",");
	}
}

void	printh(t_data stacks)
{
	t_list	*a;
	t_list	*b;

	printf("----------------------------------\n");
	printf("stack_a: ");
	print_lst_h(stacks.a->lst);
	printf("\nstack_b: ");
	print_lst_h(stacks.b->lst);
	printf("\n");
	printf("----------------------------------\n");
}

void	printv(t_data stacks)
{
	t_list	*a;
	t_list	*b;

	a = stacks.a->lst;
	b = stacks.b->lst;
	ft_putstr_fd("stack_a\t\tstack_b\n-------\t\t-------\n", 0);
	while (a || b)
	{
		if (a != NULL)
		{
			if (a->content != NULL)
				printf("%d", *(int *)(a->content));
			a = a->next;
		}
		printf(" \t\t");
		if (b != NULL)
		{
			if (b->content != NULL)
				printf("%d", *(int *)(b->content));
			b = b->next;
		}
		printf("\n");
	}
	printf("\n");
}
