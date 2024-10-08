/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_internals.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:31:13 by poss              #+#    #+#             */
/*   Updated: 2024/08/19 13:38:01 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_INTERNALS_H
# define LOAD_INTERNALS_H

# include "error/t_error.h"
# include "optionals.h"
# include "stack/t_stacks.h"

t_error		load_stacks_from_string(const char *numbers, t_stacks *stacks_out);
t_error		load_stacks_from_strings(const char **numbers, int len,
				t_stacks *out);
t_opt_int	checked_atoi(const char *s);
t_opt_uint	checked_atou(const char *s);

#endif
