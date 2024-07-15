#include "t_int_deque.h"

t_int_deque	deque_new(void)
{
	return ((t_int_deque){.head = NULL, .tail = NULL});
}
