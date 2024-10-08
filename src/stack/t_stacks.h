/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stacks.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:03:19 by vlafouas          #+#    #+#             */
/*   Updated: 2024/08/19 13:36:39 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_STACKS_H
# define T_STACKS_H

# include "deque/t_int_deque.h"

typedef struct s_stacks	t_stacks;
struct					s_stacks
{
	t_int_deque			a;
	t_int_deque			b;
};

typedef enum e_operation
{
	NULL_OP,
	OP_SWAP_A,
	OP_SWAP_B,
	OP_SWAP_BOTH,
	OP_PUSH_ONTO_A,
	OP_PUSH_ONTO_B,
	OP_ROTATE_A,
	OP_ROTATE_B,
	OP_ROTATE_BOTH,
	OP_RROTATE_A,
	OP_RROTATE_B,
	OP_RROTATE_BOTH,
}						t_operation;

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

#endif
