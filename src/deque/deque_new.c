/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:30:25 by poss              #+#    #+#             */
/*   Updated: 2024/08/13 23:30:25 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_int_deque.h"

t_int_deque	deque_new(void)
{
	return ((t_int_deque){.head = NULL, .tail = NULL, .sz = 0});
}
