/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:31:28 by poss              #+#    #+#             */
/*   Updated: 2024/08/13 23:31:28 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_stacks.h"

void	rotate_a(t_stacks *stacks)
{
	if (!stacks)
		return ;
	deque_rotate_pull(&stacks->a);
}

void	rotate_b(t_stacks *stacks)
{
	if (!stacks)
		return ;
	deque_rotate_pull(&stacks->b);
}

void	rotate_both(t_stacks *stacks)
{
	rotate_a(stacks);
	rotate_b(stacks);
}
