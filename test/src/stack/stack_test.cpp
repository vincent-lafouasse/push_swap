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

void log_deque(const t_int_deque dq, const char* name)
{
    std::cout << name << " : ";
    if (!dq.head)
    {
        std::cout << std::endl;
        return;
    }

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

void log_a(const t_stacks s)
{
    log_deque(s.a, "a");
}

void log_b(const t_stacks s)
{
    log_deque(s.b, "b");
}

TEST(Stack, Swap)
{
    const Vector a{1, 2, 3, 4};
    const Vector b{5, 6, 7, 8};
    t_stacks stacks = {.a = deque_from_vec(a), .b = deque_from_vec(b)};

    swap_a(&stacks);
    assert_deque_eq(stacks.a, {2, 1, 3, 4});
    assert_deque_eq(stacks.b, {5, 6, 7, 8});

    swap_b(&stacks);
    assert_deque_eq(stacks.a, {2, 1, 3, 4});
    assert_deque_eq(stacks.b, {6, 5, 7, 8});

    swap_both(&stacks);
    assert_deque_eq(stacks.a, a);
    assert_deque_eq(stacks.b, b);
}

TEST(Stack, SwapNoOp)
{
    const Vector a{69};
    const Vector b{};
    t_stacks stacks = {.a = deque_from_vec(a), .b = deque_from_vec(b)};

    swap_a(&stacks);
    assert_deque_eq(stacks.a, a);
    assert_deque_eq(stacks.b, b);

    swap_b(&stacks);
    assert_deque_eq(stacks.a, a);
    assert_deque_eq(stacks.b, b);
}

TEST(Stack, Push)
{
    const Vector a{};
    const Vector b{1, 2, 3};
    t_stacks stacks = {.a = deque_from_vec(a), .b = deque_from_vec(b)};

    push_a(&stacks);
    assert_deque_eq(stacks.a, {1});
    assert_deque_eq(stacks.b, {2, 3});

    push_a(&stacks);
    assert_deque_eq(stacks.a, {2, 1});
    assert_deque_eq(stacks.b, {3});

    push_a(&stacks);
    assert_deque_eq(stacks.a, {3, 2, 1});
    assert_deque_eq(stacks.b, {});

    push_a(&stacks);
    assert_deque_eq(stacks.a, {3, 2, 1});
    assert_deque_eq(stacks.b, {});

    push_b(&stacks);
    push_b(&stacks);
    push_b(&stacks);
    push_b(&stacks);
    push_b(&stacks);
    push_b(&stacks);
    assert_deque_eq(stacks.a, a);
    assert_deque_eq(stacks.b, b);
}

TEST(Stack, RotateNoOp)
{
    const Vector a{};
    const Vector b{1};
    t_stacks stacks = {.a = deque_from_vec(a), .b = deque_from_vec(b)};

    rotate_a(&stacks);
    assert_deque_eq(stacks.a, a);
    assert_deque_eq(stacks.b, b);

    rrotate_a(&stacks);
    assert_deque_eq(stacks.a, a);
    assert_deque_eq(stacks.b, b);

    rotate_b(&stacks);
    assert_deque_eq(stacks.a, a);
    assert_deque_eq(stacks.b, b);

    rrotate_b(&stacks);
    assert_deque_eq(stacks.a, a);
    assert_deque_eq(stacks.b, b);
}

TEST(Stack, Rotate)
{
    const Vector a{1, 2, 3};
    const Vector b{-1, -2, -3};
    t_stacks stacks = {.a = deque_from_vec(a), .b = deque_from_vec(b)};

    rotate_a(&stacks);
    assert_deque_eq(stacks.a, {2, 3, 1});
    assert_deque_eq(stacks.b, {-1, -2, -3});

    rotate_a(&stacks);
    assert_deque_eq(stacks.a, {3, 1, 2});
    assert_deque_eq(stacks.b, {-1, -2, -3});

    rrotate_b(&stacks);
    assert_deque_eq(stacks.a, {3, 1, 2});
    assert_deque_eq(stacks.b, {-3, -1, -2});

    rotate_both(&stacks);
    assert_deque_eq(stacks.a, a);
    assert_deque_eq(stacks.b, b);
}
