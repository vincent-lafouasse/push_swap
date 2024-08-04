#pragma once

#include <stdbool.h>

typedef struct s_opt_int
{
	int val;
	bool is_valid;
} t_opt_int;

typedef struct s_opt_uint
{
	unsigned int val;
	bool is_valid;
} t_opt_uint;


t_opt_int	opt_int_none(void);
t_opt_uint	opt_uint_none(void);
