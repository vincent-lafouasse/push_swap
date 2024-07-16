#pragma once

#include <vector>

extern "C"
{
#include "deque/t_int_deque.h"
};

void assert_deque_eq(const t_int_deque dq, const std::vector<int>& expected);
