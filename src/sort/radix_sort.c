#include "sort.h"

static void split_binary_buckets(t_stacks* stacks, size_t bit_position);
static void append_binary_buckets(t_stacks* stacks);
static size_t n_bits(uint32_t n);

void radix_sort(t_stacks* stacks)
{
	size_t bit_depth = n_bits(stacks->a.sz);
	size_t i = 0;
	while (i <= bit_depth)
	{
		split_binary_buckets(stacks, i);
		append_binary_buckets(stacks);
		i++;
	}
}

static size_t n_bits(uint32_t n)
{
	size_t out = 0;

	while (n)
	{
		n /= 2;
		out++;
	}
	return out;
}

static void split_binary_buckets(t_stacks* stacks, size_t bit_position)
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

static void append_binary_buckets(t_stacks* stacks)
{
	while (stacks->b.sz)
		push_a(stacks);
}
