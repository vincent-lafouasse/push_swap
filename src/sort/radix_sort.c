/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:29:32 by poss              #+#    #+#             */
/*   Updated: 2024/08/13 23:29:33 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque/t_int_deque.h"
#include "sort_internals.h"

static t_error	split_binary_buckets(t_stacks *stacks, size_t bit_position,
					t_int_deque *ops);
static t_error	append_binary_buckets(t_stacks *stacks, t_int_deque *ops);
static size_t	n_bits(uint32_t n);

t_error	radix_sort(t_stacks *stacks, t_int_deque *ops_out)
{
	size_t	bit_depth;
	size_t	i;
	t_error	err;

	if (!stacks || !ops_out)
		return (ERROR_NULL_OUT_PARAM);
	bit_depth = n_bits(stacks->a.sz);
	i = 0;
	*ops_out = deque_new();
	while (i < bit_depth)
	{
		if (deque_is_sorted(stacks->a))
			break ;
		err = split_binary_buckets(stacks, i, ops_out);
		if (err != NO_ERROR)
			return (err);
		err = append_binary_buckets(stacks, ops_out);
		if (err != NO_ERROR)
			return (err);
		i++;
	}
	return (NO_ERROR);
}

static t_error	split_binary_buckets(t_stacks *stacks, size_t bit_position,
		t_int_deque *ops)
{
	size_t	sz;
	size_t	i;

	sz = stacks->a.sz;
	i = 0;
	while (i < sz)
	{
		if ((deque_peek_front(stacks->a)->val >> bit_position) & 1)
		{
			rotate_a(stacks);
			if (deque_push_back(ops, OP_ROTATE_A) == false)
				return (ERROR_OOM);
		}
		else
		{
			push_b(stacks);
			if (deque_push_back(ops, OP_PUSH_ONTO_B) == false)
				return (ERROR_OOM);
		}
		i++;
	}
	return (NO_ERROR);
}

static t_error	append_binary_buckets(t_stacks *stacks, t_int_deque *ops)
{
	while (stacks->b.sz)
	{
		push_a(stacks);
		if (deque_push_back(ops, OP_PUSH_ONTO_A) == false)
			return (ERROR_OOM);
	}
	return (NO_ERROR);
}

static size_t	n_bits(uint32_t n)
{
	size_t	out;

	out = 0;
	while (n)
	{
		n /= 2;
		out++;
	}
	return (out);
}
