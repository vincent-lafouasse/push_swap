/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checked_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:30:56 by poss              #+#    #+#             */
/*   Updated: 2024/08/13 23:50:55 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load_internals.h"

static t_u32	ft_abs(t_i32 n);

t_opt_int	checked_atoi(const char *s)
{
	t_u32	absolute_value;
	t_i8	sign;

	if (!s)
		return (int_none());
	sign = 1;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	if (!checked_atou(s).is_valid)
		return (int_none());
	absolute_value = checked_atou(s).val;
	if (sign == 1 && absolute_value > INT32_MAX)
		return (int_none());
	if (sign == -1 && absolute_value > ft_abs(INT32_MIN))
		return (int_none());
	return (int_ok(sign * absolute_value));
}

static t_u32	ft_abs(t_i32 n)
{
	t_i64	n__;

	n__ = n;
	if (n__ >= 0)
		return (n__);
	else
		return (-n__);
}
