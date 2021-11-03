/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:41:58 by pmontese          #+#    #+#             */
/*   Updated: 2019/11/26 15:38:58 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*trimmed_str;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && ft_iscontained(s1[start], set))
		start++;
	end = ft_strlen(s1) > 0 ? ft_strlen(s1) - 1 : 0;
	while (end > start && ft_iscontained(s1[end], set))
		end--;
	if (!(trimmed_str = (char*)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	i = 0;
	while (i + start <= end)
	{
		trimmed_str[i] = s1[start + i];
		i++;
	}
	trimmed_str[i] = '\0';
	return (trimmed_str);
}
