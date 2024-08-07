#include "error/t_error.h"
#include "load_internals.h"

static t_opt_uint checked_atou(const char* s);

static t_u32 ft_abs(t_i32 n)
{
	if (n >= 0)
		return n;
	else
		return -n;
}

t_opt_int	checked_atoi(const char *s)
{
	t_u32 absolute_value;
	t_i8 sign;

	if (!s)
		return (opt_int_none());
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else
		sign = 1;
	if (checked_atou(s).is_valid)
		absolute_value = checked_atou(s).val;
	else
		return opt_int_none();
	if ((sign == 1 && absolute_value > INT32_MAX) || (sign == -1 && absolute_value > ft_abs(INT32_MIN)))
		return opt_int_none();
	return (t_opt_int){.val=sign * absolute_value, .is_valid=true};
}
