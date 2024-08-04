#include "libft/ft_string.h"
#include "load_internals.h"

t_opt_int	checked_atoi(const char *s)
{
	const char	*trimmed;
	int			val;

	val = 0;
	if (!s)
		return (opt_int_none());
	trimmed = ft_strtrim(s, " \v\t\r\n");
	if (!trimmed)
		return (opt_int_none());
	return (opt_int_none());
}
