#pragma once

#include <vector>

extern "C"
{
#include "deque/t_int_deque.h"
#include "libft/types.h"
};

void assert_deque_eq(const t_int_deque dq, const std::vector<t_i32>& expected);
