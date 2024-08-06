#include "sort/sort.h"
#include "deque/t_int_deque.h"
#include "stack/t_stacks.h"
#include "load/load.h"
#include "log/log.h"

#include <stdint.h>
#include <stdio.h> // living dangerously


size_t n_bits(uint32_t n)
{
	size_t out = 0;

	while (n)
	{
		n /= 2;
		out++;
	}
	return out;
}

void split_binary_buckets(t_stacks* stacks, size_t bit_position)
{
	size_t sz = stacks->a.sz;
	size_t i = 0;

	while (i < sz)
	{
		if ((deque_peek_front(stacks->a)->val >> bit_position) & 1)
			rotate_a(stacks);
		else
			push_b(stacks);
		i++;
	}
}

void append_binary_buckets(t_stacks* stacks)
{
	while (stacks->b.sz)
		push_a(stacks);
}

int	main(int ac, char** av)
{
	t_stacks	stacks;

	stacks = stacks_from_strings((const char**)av + 1, ac - 1);
	simplify(&stacks.a);
	log_deque(stacks.a, NULL, false);

	size_t bit_depth = n_bits(stacks.a.sz);
	size_t i = 0;
	while (i <= bit_depth)
	{
		split_binary_buckets(&stacks, i);
		append_binary_buckets(&stacks);
		i++;
	}

	log_deque(stacks.a, NULL, false);
}
