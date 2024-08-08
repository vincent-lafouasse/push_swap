#include "load_internals.h"
#include "libft/ft_string.h"

static int string_array_len(const char** strs);

t_error load_stacks_from_string(const char* numbers, t_stacks* out)
{
	char** split_numbers;
	int sz;

	split_numbers = ft_split(numbers, ' ');
	if (split_numbers == NULL)
	{
		return ERROR_OOM;
	}
	sz = string_array_len((const char**)split_numbers);
	return load_stacks_from_strings((const char**)split_numbers, sz, out);
}

static int string_array_len(const char** strs)
{
	int len;

	if (!strs)
		return 0;
	len = 0;
	while (*strs)
	{
		strs++;
		len++;
	}
	return len;
}
