/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:31:11 by poss              #+#    #+#             */
/*   Updated: 2024/08/13 23:31:12 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error/t_error.h"
#include "load.h"
#include "load_internals.h"

t_error	load_stacks(const char **numbers, int len, t_stacks *out)
{
	t_error	err;

	err = load_stacks_from_strings(numbers, len, out);
	if (err == NO_ERROR)
	{
		return (NO_ERROR);
	}
	return (load_stacks_from_string(numbers[0], out));
}
