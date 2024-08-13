#pragma once

#include "error/t_error.h"
#include "optionals.h"
#include "stack/t_stacks.h"

t_error		load_stacks_from_string(const char *numbers, t_stacks *out);
t_error		load_stacks_from_strings(const char **numbers, int len,
				t_stacks *out);
t_opt_int	checked_atoi(const char *s);
t_opt_uint	checked_atou(const char *s);
