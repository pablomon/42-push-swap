/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:37:46 by pmontese          #+#    #+#             */
/*   Updated: 2021/11/01 15:14:43 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	msb(int n)
{
	int	pos;
	int	i;

	i = 0;
	while (i < sizeof(int) * 8)
	{
		if ((n >> i) & 1)
			pos = i;
		i++;
	}
	return (pos);
}

// USAR DO MOVE
void	radix_short(t_data ss, int input_len)
{
	int		bit_pos;
	t_list	*link;
	int		bit;
	int		i;
	int		msb_pos;

	msb_pos = msb(input_len - 1);
	bit_pos = 0;
	while (bit_pos < msb_pos + 1)
	{
		i = 0;
		while (i < input_len)
		{
			bit = ((val(ss.a->lst, 0)) >> bit_pos) & 1;
			if (bit == 0)
				*ss.moves += pusha2b(ss);
			else
				*ss.moves += shiftupa(ss);
			i++;
		}
		while (ss.b->lst)
			*ss.moves += pushb2a(ss);
		bit_pos++;
	}
}
