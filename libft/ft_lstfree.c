
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:48:01 by pmontese          #+#    #+#             */
/*   Updated: 2019/11/25 17:46:02 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list *lst)
{
	t_list	*nod;

	if (lst)
	{
		while (lst)
		{
			nod = lst->next;
			free(lst->content);
			lst->content = NULL;
			free(lst);
			lst = NULL;
			lst = nod;
		}
	}
}
