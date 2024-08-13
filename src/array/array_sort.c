/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:29:52 by poss              #+#    #+#             */
/*   Updated: 2024/08/13 23:29:53 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_operations.h"
#include <stdbool.h>

static void	ft_swap(t_i32 *a, t_i32 *b);

void	sort_array(t_i32 *array, size_t len)
{
	bool	is_sorted;
	int		i;

	is_sorted = false;
	while (!is_sorted)
	{
		is_sorted = true;
		i = 0;
		while (i < (int)len - 1)
		{
			if (array[i] > array[i + 1])
			{
				ft_swap(array + i, array + i + 1);
				is_sorted = false;
			}
			i++;
		}
	}
}

static void	ft_swap(t_i32 *a, t_i32 *b)
{
	t_i32	buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}
