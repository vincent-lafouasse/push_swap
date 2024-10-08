/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains_duplicates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:29:39 by poss              #+#    #+#             */
/*   Updated: 2024/08/13 23:39:29 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_operations.h"

bool	sorted_array_contains_duplicates(const t_i32 *sorted_array, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len - 1)
	{
		if (sorted_array[i] == sorted_array[i + 1])
			return (true);
		i++;
	}
	return (false);
}
