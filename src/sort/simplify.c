/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:29:20 by poss              #+#    #+#             */
/*   Updated: 2024/08/16 13:25:53 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array/array_operations.h"
#include "error/t_error.h"
#include "sort.h"
#include <stdlib.h>

static t_error	simplify(t_int_deque *dq, const t_i32 *sorted);

t_error	simplify_verify(t_int_deque *dq)
{
	t_i32	*sorted_data;
	t_error	err;

	sorted_data = deque_copy_into_array(*dq);
	if (sorted_data == NULL)
		return (ERROR_OOM);
	sort_array(sorted_data, dq->sz);
	if (sorted_array_contains_duplicates(sorted_data, dq->sz))
	{
		free(sorted_data);
		return (ERROR_DUPLICATES);
	}
	err = simplify(dq, sorted_data);
	free(sorted_data);
	return (err);
}

static t_error	simplify(t_int_deque *dq, const t_i32 *sorted)
{
	int			index;
	t_int_list	*current;
	t_int_deque	out;

	if (!dq || !sorted)
		return (ERROR_NULL_OUT_PARAM);
	current = dq->head;
	out = deque_new();
	while (current)
	{
		index = index_of(current->val, sorted, dq->sz);
		if (index < 0)
			return (deque_clear(&out), ERROR_ELEMENT_NOT_FOUND);
		deque_push_back(&out, index);
		current = current->next;
	}
	deque_clear(dq);
	*dq = out;
	return (NO_ERROR);
}
