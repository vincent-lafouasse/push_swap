/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stacks_from_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:30:54 by poss              #+#    #+#             */
/*   Updated: 2024/08/17 13:24:39 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error/t_error.h"
#include "libft/ft_string.h"
#include "load_internals.h"
#include <stdlib.h>

static int	string_array_len(const char **strs);
static void	free_string_array(char **strs);

t_error	load_stacks_from_string(const char *numbers, t_stacks *out)
{
	char	**split_numbers;
	int		sz;
	t_error	err;

	if (numbers[0] == '\0')
	{
		out->a = deque_new();
		out->b = deque_new();
		return (ERROR_NOT_A_NUMBER);
	}
	split_numbers = ft_split(numbers, ' ');
	if (split_numbers == NULL)
	{
		out->a = deque_new();
		out->b = deque_new();
		return (ERROR_OOM);
	}
	sz = string_array_len((const char **)split_numbers);
	err = load_stacks_from_strings((const char **)split_numbers, sz, out);
	free_string_array(split_numbers);
	return (err);
}

static void	free_string_array(char **strs)
{
	int i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
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
