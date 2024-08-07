#pragma once

#include "stack/t_stacks.h"
#include "error/t_error.h"

t_error stacks_from_strings(const char** numbers, int len, t_stacks* out);
