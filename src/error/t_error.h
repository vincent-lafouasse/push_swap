/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_error.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:31:37 by poss              #+#    #+#             */
/*   Updated: 2024/08/15 19:58:24 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef enum e_error
{
	NO_ERROR,
	ERROR_OOM,
	ERROR_DUPLICATES,
	ERROR_NOT_A_NUMBER,
	ERROR_NULL_OUT_PARAM,
	ERROR_ELEMENT_NOT_FOUND,
	ERROR_UNREACHABLE,
}			t_error;

const char	*error_repr(t_error err);
