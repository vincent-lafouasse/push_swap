#pragma once

#include "error/t_error.h"
#include "stack/t_stacks.h"

t_error	radix_sort(t_stacks *stacks, t_int_deque *ops_out);
t_error	sort2(t_stacks *stacks, t_int_deque *ops_out);
