/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_operations.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:29:47 by poss              #+#    #+#             */
/*   Updated: 2024/08/19 13:38:31 by vlafouas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_OPERATIONS_H
# define ARRAY_OPERATIONS_H

# include "libft/types.h"
# include <stdbool.h>

void	sort_array(t_i32 *array, size_t len);
int		index_of(t_i32 value, const t_i32 *array, size_t len);
bool	array_is_sorted(const t_i32 *array, size_t len);
bool	sorted_array_contains_duplicates(const t_i32 *sorted_array, size_t len);

#endif
