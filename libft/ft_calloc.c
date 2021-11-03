/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:42:43 by pmontese          #+#    #+#             */
/*   Updated: 2019/11/25 17:45:58 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char *ptr;

	if (!(ptr = (char*)malloc(sizeof(char) * count * size)))
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}
