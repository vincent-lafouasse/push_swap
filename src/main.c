#include "stack/t_stacks.h"
#include "deque/t_int_deque.h"
#include "log/log.h"

int	main(void)
{
	t_stacks	stacks;

	stacks.a = deque_new();
	stacks.b = deque_new();
	log_stacks_horizontal(stacks);
}
