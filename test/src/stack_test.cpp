#include <iostream>
#include "gtest/gtest.h"

#include "custom_assertions.h"

extern "C"
{
#include "stack/t_stacks.h"
};

typedef std::vector<int> Vector;

struct Deque
{
    t_int_deque dq;

    static t_int_deque from_vec(const Vector& v)
    {
        t_int_deque dq = deque_new();
        for (int e : v)
        {
            deque_push_back(&dq, e);
        }
        assert_deque_eq(dq, v);
        return dq;
    }
};

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

struct Stacks
{
    t_stacks s;

    static t_stacks from_vecs(const Vector& a, const Vector& b)
    {
        t_stacks s;
        s.a = Deque::from_vec(a);
        s.b = Deque::from_vec(b);
        return s;
    }
};

TEST(Stack, Swap)
{
    Vector a{1, 2, 3, 4};
    Vector b{5, 6, 7, 8};
    t_stacks stacks = Stacks::from_vecs(a, b);

    swap_a(&stacks);
    Vector expected_a{2, 1, 3, 4};
    Vector expected_b{5, 6, 7, 8};

    // assert_deque_eq(stacks.a, expected_a);
    assert_deque_eq(stacks.b, expected_b);
}
