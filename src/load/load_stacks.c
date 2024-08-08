#include "error/t_error.h"
#include "load.h"
#include "load_internals.h"

t_error	load_stacks(const char **numbers, int len, t_stacks *out)
{
	t_error err;

	err = load_stacks_from_strings(numbers, len, out);
	if (err == NO_ERROR)
	{
		return NO_ERROR;
	}
	return (load_stacks_from_string(numbers[0], out));
}
