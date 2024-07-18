#pragma once

#include "stack/t_stacks.h"
#include "deque/t_int_deque.h"

/*
 * load raw stacks = just the numbers, check if valid strings but that's it
 * load simplified = assign equivalent in N
*/

t_stacks stacks_from_strings(const char** numbers, int len);
t_int_deque load_raw_stack(const char** numbers, int len);
