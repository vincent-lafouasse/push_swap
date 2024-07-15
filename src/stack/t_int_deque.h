/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_int_deque.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:59:22 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/15 12:43:27 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdbool.h>
#include <stddef.h>

typedef struct s_int_list	t_int_list;
struct						s_int_list
{
	const int				val;
	t_int_list				*next;
	t_int_list				*prev;
};

t_int_list* list_new(int val);

typedef struct s_int_deque
{
	t_int_list				*head;
	t_int_list				*tail;
}							t_int_deque;

t_int_deque					deque_new(void);
int							deque_peak_front(const t_int_deque dq);
int							deque_peak_back(const t_int_deque dq);
int							deque_pop_front(t_int_deque *dq);
int							deque_pop_back(t_int_deque *dq);
bool						deque_push_front(t_int_deque *dq, int val);
bool						deque_push_back(t_int_deque *dq, int val);
bool						deque_is_empty(const t_int_deque dq);
size_t						deque_size(const t_int_deque dq);
void						deque_rotate_one(t_int_deque* dq);
void						deque_rrotate_one(t_int_deque* dq);
void						deque_clear(t_int_deque* dq);
