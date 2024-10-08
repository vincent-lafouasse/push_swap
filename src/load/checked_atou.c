/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checked_atou.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:31:05 by poss              #+#    #+#             */
/*   Updated: 2024/08/13 23:31:05 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ctype.h"
#include "libft/string.h"
#include "load_internals.h"

#define STR_U32_MAX "4294967295"

static bool	str_is_all_numbers(const char *s);
static bool	will_overflow_u32(const char *s);

t_opt_uint	checked_atou(const char *s)
{
	t_u32	val;

	if (!s || !str_is_all_numbers(s) || !*s)
		return (uint_none());
	if (*s == '0' && *(s + 1) != '\0')
		return (uint_none());
	if (will_overflow_u32(s))
		return (uint_none());
	val = 0;
	while (*s)
	{
		val = 10 * val + (*s - '0');
		s++;
	}
	return (uint_ok(val));
}

static bool	str_is_all_numbers(const char *s)
{
	if (!s)
		return (false);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (false);
		s++;
	}
	return (true);
}

static bool	will_overflow_u32(const char *s)
{
	if (ft_strlen(s) > ft_strlen(STR_U32_MAX))
		return (true);
	if (ft_strlen(s) < ft_strlen(STR_U32_MAX))
		return (false);
	return (ft_strncmp(s, STR_U32_MAX, ft_strlen(STR_U32_MAX)) > 0);
}
