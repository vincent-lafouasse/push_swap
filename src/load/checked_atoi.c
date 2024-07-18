#include "libft/ft_string.h"
#include "load_internals.h"

static t_opt_int	invalid(void);

t_opt_int	checked_atoi(const char *s)
{
	const char	*trimmed;
	int			val;

	val = 0;
	if (!s)
		return (invalid());
	trimmed = ft_strtrim(s, " \v\t\r\n");
	if (!trimmed)
		return (invalid());
	return (invalid());
}

static t_opt_int	invalid(void)
{
	return ((t_opt_int){.val = 0, .is_valid = false});
}
