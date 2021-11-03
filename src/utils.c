/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:37:57 by pmontese          #+#    #+#             */
/*   Updated: 2021/11/01 13:38:12 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	overflows(const char *str)
{
	int			i;
	int			sign;
	long int	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = (nbr * 10) + (str[i++] - '0');
	nbr *= sign;
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (1);
	return (0);
}

int	is_valid_int(const char *str)
{
	const char	*ptr;

	while (ft_isspace(*str))
		str++;
	ptr = str;
	if (*ptr != '-' && *ptr != '+' && !ft_isdigit(*ptr))
		return (0);
	ptr++;
	while (*ptr)
	{
		if (!ft_isdigit(*ptr))
			return (0);
		ptr++;
	}
	if (overflows(str))
		return (0);
	return (1);
}

int	is_sorted(t_list *lst)
{
	int	prev;
	int	val;

	if (ft_lstsize(lst) < 2)
		return (1);
	prev = *(int *)(lst->content);
	lst = lst->next;
	while (lst)
	{
		val = *(int *)(lst->content);
		if (val <= prev)
			return (0);
		prev = val;
		lst = lst->next;
	}
	return (1);
}

int	is_progression(t_list *lst)
{
	int	inflections;
	int	head_val;
	int	prev_val;
	int	val;

	head_val = *(int *)(lst->content);
	prev_val = head_val;
	lst = lst->next;
	inflections = 0;
	while (lst)
	{
		val = *(int *)(lst->content);
		if (prev_val > val)
			inflections ++;
		prev_val = val;
		lst = lst->next;
		if (!lst)
			if (val > head_val)
				inflections ++;
	}
	if (inflections > 1)
		return (0);
	return (1);
}

t_list	*lstdup(t_list *lst)
{
	t_list	*duplicate;
	t_list	*tmp;
	int		*ptr;

	duplicate = NULL;
	while (lst)
	{
		if (lst->content)
		{
			ptr = (int *)(malloc(sizeof(int)));
			if (!ptr)
				return (NULL);
			*ptr = (*(int *)lst->content);
		}
		ft_lstadd_back(&duplicate, ft_lstnew(ptr));
		lst = lst->next;
	}
	return (duplicate);
}
