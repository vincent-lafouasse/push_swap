/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_repr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:31:49 by poss              #+#    #+#             */
/*   Updated: 2024/08/13 23:31:50 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_error.h"

const char	*error_repr(t_error err)
{
	if (err == NO_ERROR)
		return ("Ok");
	if (err == ERROR_OOM)
		return ("Out of memory");
	if (err == ERROR_DUPLICATES)
		return ("Duplicates in input");
	if (err == ERROR_NOT_A_NUMBER)
		return ("Input is not a number");
	if (err == ERROR_NULL_OUT_PARAM)
		return ("Out param is NULL");
	if (err == ERROR_ELEMENT_NOT_FOUND)
		return ("Element not found");
	return ("Unrecognised error");
}
