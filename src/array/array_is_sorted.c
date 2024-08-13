/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:29:42 by poss              #+#    #+#             */
/*   Updated: 2024/08/13 23:29:42 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_operations.h"

bool	array_is_sorted(const t_i32 *array, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len - 1)
	{
		if (array[i] > array[i + 1])
			return (false);
		i++;
	}
	return (true);
}
