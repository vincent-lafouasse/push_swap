#include "error/t_error.h"
#include "load_internals.h"
#include"libft/ctype.h"

static t_opt_uint	checked_atou(const char *s);
static bool str_is_all_numbers(const char* s);
static t_u32	ft_abs(t_i32 n);

t_opt_int	checked_atoi(const char *s)
{
	t_u32	absolute_value;
	t_i8	sign;

	if (!s)
		return (opt_int_none());
	sign = 1;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	if (!checked_atou(s).is_valid)
		return (opt_int_none());
	absolute_value = checked_atou(s).val;
	if ((sign == 1 && absolute_value > INT32_MAX) || (sign == -1
			&& absolute_value > ft_abs(INT32_MIN)))
		return (opt_int_none());
	return ((t_opt_int){.val = sign * absolute_value, .is_valid = true});
}

static t_opt_uint	checked_atou(const char *s)
{
	if (!s || !str_is_all_numbers(s))
		return opt_uint_none();
	return opt_uint_none();
}

static bool str_is_all_numbers(const char* s)
{
	if (!s)
		return false;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return false;
		s++;
	}
	return true;
}

static t_u32	ft_abs(t_i32 n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}
