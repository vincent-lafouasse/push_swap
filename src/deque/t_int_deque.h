/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_int_deque.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:59:22 by vlafouas          #+#    #+#             */
/*   Updated: 2024/08/04 11:42:43 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdbool.h>
#include "libft/types.h"

typedef struct s_int_list	t_int_list;
struct						s_int_list
{
	const t_i32				val;
	t_int_list				*next;
	t_int_list				*prev;
};

t_int_list					*list_new(t_i32 val);

typedef struct s_int_deque
{
	t_int_list				*head;
	t_int_list				*tail;
	size_t					sz;
}							t_int_deque;

t_int_deque					deque_new(void);
t_int_deque					deque_deep_copy(const t_int_deque dq);
const t_int_list			*deque_peek_back(const t_int_deque dq);
const t_int_list			*deque_peek_front(const t_int_deque dq);
t_int_list					*deque_pop_front(t_int_deque *dq);
t_int_list					*deque_pop_back(t_int_deque *dq);
bool						deque_push_front(t_int_deque *dq, t_i32 val);
bool						deque_push_back(t_int_deque *dq, t_i32 val);
void						deque_push_front_link(t_int_deque *dq,
								t_int_list *link);
void						deque_push_back_link(t_int_deque *dq,
								t_int_list *link);
bool						deque_is_empty(const t_int_deque dq);
size_t						deque_size(const t_int_deque dq);
void						deque_rotate_push(t_int_deque *dq);
void						deque_rotate_pull(t_int_deque *dq);
void						deque_clear(t_int_deque *dq);

void deque_sort(t_int_deque* dq);
t_i32* deque_copy_into_array(const t_int_deque dq);
