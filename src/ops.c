/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:37:38 by pmontese          #+#    #+#             */
/*   Updated: 2021/11/01 13:38:16 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swapa(t_data stacks)
{
	writeop(stacks, "sa\n");
	return (swap(stacks.a));
}

int	pusha2b(t_data stacks)
{
	writeop(stacks, "pb\n");
	return (push(stacks.a, stacks.b));
}

int	pushb2a(t_data stacks)
{
	writeop(stacks, "pa\n");
	return (push(stacks.b, stacks.a));
}

int	shiftupa(t_data stacks)
{
	writeop(stacks, "ra\n");
	return (shiftup(stacks.a));
}

int	shiftdowna(t_data stacks)
{
	writeop(stacks, "rra\n");
	return (shiftdown(stacks.a));
}
