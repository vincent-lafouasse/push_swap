/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stacks_from_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:30:54 by poss              #+#    #+#             */
/*   Updated: 2024/08/16 13:21:15 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error/t_error.h"
#include "libft/ft_string.h"
#include "load_internals.h"
#include <stdlib.h>

static int	string_array_len(const char **strs);
static void free_string_array(char** strs);

t_error	load_stacks_from_string(const char *numbers, t_stacks *out)
{
	char	**split_numbers;
	int		sz;
	t_error err;

	if (numbers[0] == '\0')
	{
		return (ERROR_NOT_A_NUMBER);
	}
	split_numbers = ft_split(numbers, ' ');
	if (split_numbers == NULL)
	{
		return (ERROR_OOM);
	}
	sz = string_array_len((const char **)split_numbers);
	err = load_stacks_from_strings((const char **)split_numbers, sz, out);
	free_string_array(split_numbers);
	return err;
}

static void free_string_array(char** strs)
{
	if (!strs)
		return ;
	while (*strs)
	{
		free(*strs);
		strs++;
	}
}

static int	string_array_len(const char **strs)
{
	int	len;

	if (!strs)
		return (0);
	len = 0;
	while (*strs)
	{
		strs++;
		len++;
	}
	return (len);
}
