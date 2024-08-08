#include "load_internals.h"
#include "libft/ft_string.h"

static int string_array_len(const char** strs);

t_error load_stacks_from_string(const char* numbers, t_stacks* out)
{
	char** split_numbers;

	split_numbers = ft_split(numbers, ' ');
	if (split_numbers == NULL)
	{
		return ERROR_OOM;
	}
	return NO_ERROR;
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
