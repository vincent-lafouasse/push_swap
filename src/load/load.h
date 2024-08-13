#pragma once

#include "error/t_error.h"
#include "stack/t_stacks.h"

t_error	load_stacks(const char **numbers, int len, t_stacks *out);
