#include <iostream>
#include "gtest/gtest.h"

#include "common/custom_assertions.h"

extern "C"
{
#include "stack/t_stacks.h"
};

typedef std::vector<int> Vector;

t_int_deque deque_from_vec(const Vector& v)
{
    t_int_deque dq = deque_new();
    for (int e : v)
    {
        deque_push_back(&dq, e);
    }
    assert_deque_eq(dq, v);
    return dq;
}

void log_deque(const t_int_deque dq)
{
    if (!dq.head)
        return;

    t_int_list* current = dq.head;
    std::cout << current->val;
    current = current->next;

    while (current)
    {
        std::cout << "->" << current->val;
        current = current->next;
    }
    std::cout << std::endl;
}

TEST(Stack, Swap)
{
    Vector a{1, 2, 3, 4};
    Vector b{5, 6, 7, 8};
    t_stacks stacks = {.a = deque_from_vec(a), .b = deque_from_vec(b)};

    swap_a(&stacks);
    assert_deque_eq(stacks.a, {2, 1, 3, 4});
    assert_deque_eq(stacks.b, {5, 6, 7, 8});

    swap_b(&stacks);
    assert_deque_eq(stacks.a, {2, 1, 3, 4});
    assert_deque_eq(stacks.b, {6, 5, 7, 8});
}
