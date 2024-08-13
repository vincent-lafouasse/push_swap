#pragma once

#include "libft/types.h"
#include <stdbool.h>

void	sort_array(t_i32 *array, size_t len);
int		index_of(t_i32 value, const t_i32 *array, size_t len);
bool	array_is_sorted(const t_i32 *array, size_t len);
bool	sorted_array_contains_duplicates(const t_i32 *sorted_array, size_t len);
