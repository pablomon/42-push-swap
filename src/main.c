/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:37:02 by pmontese          #+#    #+#             */
/*   Updated: 2021/11/03 11:24:03 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_input_lst(const char *argv[], t_data data)
{
	int		*p_int;
	t_list	*lst;

	lst = NULL;
	argv++;
	while (*argv)
	{
		p_int = (int *)(malloc(sizeof(int)));
		if (!p_int)
			exit(EXIT_FAILURE);
		*p_int = ft_atoi(*argv);
		ft_lstadd_back(&lst, ft_lstnew(p_int));
		argv++;
	}
	data.a->lst = lst;
}

void	init_fin(t_data *data, int action)
{
	if (action == INIT)
	{
		data->a = (t_stk *)(malloc(sizeof(t_stk)));
		data->a->id = 'a';
		data->a->lst = NULL;
		data->b = (t_stk *)(malloc(sizeof(t_stk)));
		data->b->id = 'b';
		data->b->lst = NULL;
		data->moves = (int *)(malloc(sizeof(int)));
		*data->moves = 0;
		data->ops = ft_strnew(0);
		data->p_ops = &data->ops;
	}
	else
	{
		ft_lstfree(data->a->lst);
		ft_lstfree(data->b->lst);
		free(data->a);
		free(data->b);
		free(data->ops);
		free(data->moves);
	}
}

void	check_duplicates(t_data data)
{
	t_list	*current;
	t_list	*temp;
	int		found;
	int		val;

	current = data.a->lst;
	while (current)
	{
		val = *(int *)current->content;
		found = 0;
		temp = data.a->lst;
		while (temp)
		{
			if (val == *(int *)temp->content)
				found++;
			temp = temp->next;
		}
		if (found > 1)
		{
			ft_putstr_fd("Error\n", 2);
			init_fin(&data, FREE);
			exit(EXIT_FAILURE);
		}
		current = current->next;
	}
}

void	check_args(int argc, char const *argv[])
{
	const char	**ptr;
	const char	*str;

	ptr = argv;
	ptr++;
	while (*ptr)
	{
		if (!is_valid_int(*ptr))
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		ptr ++;
	}
}

int	main(int argc, char const *argv[])
{
	t_data	data;
	int		len;
	int		i;

	check_args(argc, argv);
	init_fin(&data, INIT);
	make_input_lst(argv, data);
	len = ft_lstsize(data.a->lst);
	check_duplicates(data);
	if (is_sorted(data.a->lst))
	{
		init_fin(&data, FREE);
		exit(EXIT_SUCCESS);
	}
	simplify_lst(&data, len);
	if (len > 45)
		radix_short(data, len);
	else
		smallsort(data, len);
	printf("%s", data.ops);
	init_fin(&data, FREE);
	exit(EXIT_SUCCESS);
}
