/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:30:46 by poss              #+#    #+#             */
/*   Updated: 2024/08/13 23:30:47 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "error/t_error.h"
#include "stack/t_stacks.h"

t_error	load_stacks(const char **numbers, int len, t_stacks *out);
