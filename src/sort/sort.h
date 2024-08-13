#pragma once

#include "error/t_error.h"
#include "stack/t_stacks.h"

t_error	sort(t_stacks *stacks, t_int_deque *ops_out);
t_error	simplify_verify(t_int_deque *dq);
