/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_internals.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:29:16 by poss              #+#    #+#             */
/*   Updated: 2024/08/14 21:49:23 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "error/t_error.h"
#include "stack/t_stacks.h"

t_error	radix_sort(t_stacks *stacks, t_int_deque *ops_out);
t_error	sort2(t_stacks *stacks, t_int_deque *ops_out);
t_error	sort3(t_stacks *stacks, t_int_deque *ops_out);
