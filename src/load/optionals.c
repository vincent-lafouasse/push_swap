#include "optionals.h"

t_opt_int	opt_int_none(void)
{
	return ((t_opt_int){.val = 0, .is_valid = false});
}

t_opt_uint	opt_uint_none(void)
{
	return ((t_opt_uint){.val = 0, .is_valid = false});
}
