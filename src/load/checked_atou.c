#include "load_internals.h"
#include "libft/ctype.h"

static bool str_is_all_numbers(const char* s);

t_opt_uint	checked_atou(const char *s)
{
	t_u32 val;
	if (!s || !str_is_all_numbers(s))
		return opt_uint_none();
	val = 0;
	while (*s)
	{
		val = 10 * val + (*s - '0');
		s++;
	}
	return ((t_opt_uint){.val = val, .is_valid = true});
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
