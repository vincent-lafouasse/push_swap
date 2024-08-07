#include "deque/t_int_deque.h"
#include "sort.h"

static void split_binary_buckets(t_stacks* stacks, size_t bit_position, t_int_deque* ops);
static void append_binary_buckets(t_stacks* stacks, t_int_deque* ops);
static size_t n_bits(uint32_t n);

t_int_deque radix_sort(t_stacks* stacks)
{
	t_int_deque operations = deque_new();

	size_t bit_depth = n_bits(stacks->a.sz);
	size_t i = 0;
	while (i < bit_depth)
	{
		split_binary_buckets(stacks, i, &operations);
		append_binary_buckets(stacks, &operations);
		i++;
	}

	return operations;
}

static void split_binary_buckets(t_stacks* stacks, size_t bit_position, t_int_deque* ops)
{
	size_t sz = stacks->a.sz;
	size_t i = 0;

	while (i < sz)
	{
		if ((deque_peek_front(stacks->a)->val >> bit_position) & 1)
		{
			rotate_a(stacks);
			deque_push_back(ops, OP_ROTATE_A);
		}
		else
		{
			push_b(stacks);
			deque_push_back(ops, OP_PUSH_ONTO_B);
		}
		i++;
	}
}

static void append_binary_buckets(t_stacks* stacks, t_int_deque* ops)
{
	while (stacks->b.sz)
	{
		push_a(stacks);
		deque_push_back(ops, OP_PUSH_ONTO_A);
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
