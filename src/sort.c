/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:37:53 by pmontese          #+#    #+#             */
/*   Updated: 2021/11/02 12:44:14 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	val(t_list *link, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (link->next)
		{
			link = link->next;
			i++;
		}
	}
	return (*(int *)link->content);
}

void	set_int(t_list *link, int pos, int val)
{
	int		i;
	int		*pint;

	i = 0;
	while (i < pos)
	{
		if (link->next)
		{
			link = link->next;
			i++;
		}
	}
	free(link->content);
	pint = (int *)(malloc(sizeof(int)));
	*pint = val;
	link->content = pint;
}

void	writeop(t_data data, const char *op)
{
	char	*temp;
	char	*new;

	temp = *data.p_ops;
	new = ft_strjoin(*data.p_ops, op);
	*data.p_ops = new;
	free(temp);
}

void	sort_list(t_list *lst, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (val(lst, j) > val(lst, j + 1))
			{
				tmp = val(lst, j);
				set_int(lst, j, val(lst, j + 1));
				set_int(lst, j + 1, tmp);
			}
			j++;
		}
		i++;
	}
}

void	simplify_lst(t_data *data, int len)
{
	t_list	*sorted_list;
	int		i;
	int		pos;

	sorted_list = lstdup(data->a->lst);
	sort_list(sorted_list, len);
	i = 0;
	while (i < len)
	{
		pos = 0;
		while (val(data->a->lst, i) != val(sorted_list, pos))
			pos++;
		set_int(data->a->lst, i, pos);
		i++;
	}
	ft_lstfree(sorted_list);
}
