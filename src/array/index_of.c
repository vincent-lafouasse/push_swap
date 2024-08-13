/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_of.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:29:44 by poss              #+#    #+#             */
/*   Updated: 2024/08/13 23:29:45 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_operations.h"

int	index_of(t_i32 value, const t_i32 *array, size_t len)
{
	int	i;

	i = 0;
	while (i < (int)len)
	{
		if (array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
