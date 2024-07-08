/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlafouas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:59:22 by vlafouas          #+#    #+#             */
/*   Updated: 2024/07/08 16:01:07 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_STACK_H
#define T_STACK_H

typedef struct s_int_list {
	int val;
	struct s_int_list* next;
	struct s_int_list* prev;
} t_int_list;

typedef struct s_stack {
	t_int_list* head;
	t_int_list* tail;
} t_stack;

#endif
