#include "error/t_error.h"
#include "libft/ft_string.h"
#include "load_internals.h"

static int	string_array_len(const char **strs);

t_error	load_stacks_from_string(const char *numbers, t_stacks *out)
{
	char	**split_numbers;
	int		sz;

	if (numbers[0] == '\0')
	{
		return (ERROR_NOT_A_NUMBER);
	}
	split_numbers = ft_split(numbers, ' ');
	if (split_numbers == NULL)
	{
		return (ERROR_OOM);
	}
	sz = string_array_len((const char **)split_numbers);
	return (load_stacks_from_strings((const char **)split_numbers, sz, out));
}

static int	string_array_len(const char **strs)
{
	int	len;

	if (!strs)
		return (0);
	len = 0;
	while (*strs)
	{
		strs++;
		len++;
	}
	return (len);
}
