/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stacks.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:03:19 by vlafouas          #+#    #+#             */
/*   Updated: 2024/08/06 16:05:45 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "deque/t_int_deque.h"

typedef struct s_stacks t_stacks;
struct s_stacks {
  t_int_deque a;
  t_int_deque b;
};

typedef enum e_operations t_operations;
enum e_operations {
  OP_SWAP_A,
  OP_SWAP_B,
  OP_SWAP_BOTH,

  OP_PUSH_A,
  OP_PUSH_B,

  OP_ROTATE_A,
  OP_ROTATE_B,
  OP_ROTATE_BOTH,

  OP_RROTATE_A,
  OP_RROTATE_B,
  OP_RROTATE_BOTH,
};

void swap_a(t_stacks *stacks);
void swap_b(t_stacks *stacks);
void swap_both(t_stacks *stacks);

void push_a(t_stacks *stacks);
void push_b(t_stacks *stacks);

void rotate_a(t_stacks *stacks);
void rotate_b(t_stacks *stacks);
void rotate_both(t_stacks *stacks);

void rrotate_a(t_stacks *stacks);
void rrotate_b(t_stacks *stacks);
void rrotate_both(t_stacks *stacks);
