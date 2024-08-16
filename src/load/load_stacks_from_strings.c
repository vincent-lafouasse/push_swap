/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stacks_from_strings.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:31:08 by poss              #+#    #+#             */
/*   Updated: 2024/08/16 13:18:42 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load_internals.h"

t_error	load_stacks_from_strings(const char **numbers, int len,
		t_stacks *stacks_out)
{
	int	i;

	if (numbers == NULL || stacks_out == NULL)
		return (ERROR_NULL_OUT_PARAM);
	stacks_out->a = deque_new();
	stacks_out->b = deque_new();
	i = 0;
	while (i < len)
	{
		if (checked_atoi(numbers[i]).is_valid == false)
			return (ERROR_NOT_A_NUMBER);
		if (deque_push_back(&stacks_out->a,
				checked_atoi(numbers[i]).val) == false)
			return (ERROR_OOM);
		i++;
	}
	return (NO_ERROR);
}
