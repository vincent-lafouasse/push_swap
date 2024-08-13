/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optionals.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:30:51 by poss              #+#    #+#             */
/*   Updated: 2024/08/13 23:30:51 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "libft/types.h"
#include <stdbool.h>

typedef struct s_opt_int
{
	t_i32	val;
	bool	is_valid;
}			t_opt_int;

typedef struct s_opt_uint
{
	t_u32	val;
	bool	is_valid;
}			t_opt_uint;

t_opt_int	int_none(void);
t_opt_uint	uint_none(void);
t_opt_int	int_ok(t_i32 val);
t_opt_uint	uint_ok(t_u32 val);
