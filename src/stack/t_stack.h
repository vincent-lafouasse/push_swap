/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:03:19 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/15 15:37:22 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "deque/t_int_deque.h"

typedef struct s_stacks	t_stacks;
struct					s_stacks
{
	t_int_deque			a;
	t_int_deque			b;
};

void					swap_a(t_stacks *stacks);
void					swap_b(t_stacks *stacks);
void					swap_both(t_stacks *stacks);

void					push_a(t_stacks *stacks);
void					push_b(t_stacks *stacks);

void					rotate_a(t_stacks *stacks);
void					rotate_b(t_stacks *stacks);
void					rotate_both(t_stacks *stacks);

void					rrotate_a(t_stacks *stacks);
void					rrotate_b(t_stacks *stacks);
void					rrotate_both(t_stacks *stacks);
