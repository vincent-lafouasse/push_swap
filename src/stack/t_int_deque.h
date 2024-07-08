/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_int_deque.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:59:22 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/08 16:12:54 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdbool.h>
#include <stddef.h>

typedef struct s_int_list
{
	int					val;
	struct s_int_list	*next;
	struct s_int_list	*prev;
}						t_int_list;

typedef struct s_int_deque
{
	t_int_list			*head;
	t_int_list			*tail;
}						t_int_deque;

t_int_deque				deque_new(void);
int						deque_peak_front(t_int_deque dq);
int						deque_peak_back(t_int_deque dq);
int						deque_pop_front(t_int_deque dq);
int						deque_pop_back(t_int_deque dq);
bool					deque_push_front(t_int_deque dq, int val);
bool					deque_push_back(t_int_deque dq, int val);
bool					deque_is_empty(t_int_deque dq);
size_t					deque_size(t_int_deque dq);
void					deque_rotate_one(t_int_deque dq);
void					deque_rrotate_one(t_int_deque dq);
void					deque_clear(t_int_deque dq);
