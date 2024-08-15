/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:40:13 by poss              #+#    #+#             */
/*   Updated: 2024/08/15 20:41:26 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_int_deque.h"

void	deque_append(t_int_deque *dst, t_int_deque *src)
{
	if (!dst || !src)
		return ;
	while (src->sz)
		deque_push_back_link(dst, deque_pop_front(src));
}
