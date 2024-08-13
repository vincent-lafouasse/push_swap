/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:31:34 by poss              #+#    #+#             */
/*   Updated: 2024/08/13 23:31:35 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque/t_int_deque.h"
#include "t_stacks.h"

static void	swap(t_int_deque *dq);

void	swap_a(t_stacks *stacks)
{
	if (!stacks)
		return ;
	swap(&(stacks->a));
}

void	swap_b(t_stacks *stacks)
{
	if (!stacks)
		return ;
	swap(&(stacks->b));
}

void	swap_both(t_stacks *stacks)
{
	swap_a(stacks);
	swap_b(stacks);
}

static void	swap(t_int_deque *dq)
{
	t_int_list	*top;
	t_int_list	*second_top;

	if (!dq || dq->sz == 0 || dq->sz == 1)
		return ;
	top = deque_pop_front(dq);
	second_top = deque_pop_front(dq);
	deque_push_front_link(dq, top);
	deque_push_front_link(dq, second_top);
}
