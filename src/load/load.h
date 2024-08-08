#pragma once

#include "stack/t_stacks.h"
#include "error/t_error.h"

t_error load_stacks(const char** numbers, int len, t_stacks* out);
