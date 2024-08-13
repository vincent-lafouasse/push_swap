/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optionals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:31:16 by poss              #+#    #+#             */
/*   Updated: 2024/08/13 23:31:17 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "optionals.h"

t_opt_int	int_none(void)
{
	return ((t_opt_int){.val = 0, .is_valid = false});
}

t_opt_uint	uint_none(void)
{
	return ((t_opt_uint){.val = 0, .is_valid = false});
}

t_opt_int	int_ok(t_i32 val)
{
	return ((t_opt_int){.val = val, .is_valid = true});
}

t_opt_uint	uint_ok(t_u32 val)
{
	return ((t_opt_uint){.val = val, .is_valid = true});
}
