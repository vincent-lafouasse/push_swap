/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:03:19 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/15 15:32:40 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "t_int_deque.h"

typedef struct s_stacks t_stacks;
struct s_stacks {
	t_int_deque a;
	t_int_deque b;
};
