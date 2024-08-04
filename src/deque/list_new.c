#include "libft/string.h"
#include "t_int_deque.h"
#include <stdlib.h>

t_int_list	*list_new(t_i32 val)
{
	t_int_list	*out;

	out = malloc(sizeof(*out));
	if (out == NULL)
		return (NULL);
	ft_memcpy(out, &val, sizeof(val));
	out->next = NULL;
	out->prev = NULL;
	return (out);
}
