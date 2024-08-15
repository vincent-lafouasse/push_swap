#include "gtest/gtest.h"

#include <vector>
#include "common/custom_assertions.h"

extern "C"
{
#include "deque/t_int_deque.h"
};

typedef std::vector<t_i32> Vector;

t_int_deque deque_from_vec(const Vector& v)
{
    t_int_deque dq = deque_new();
    for (t_i32 e : v)
    {
        deque_push_back(&dq, e);
    }
    assert_deque_eq(dq, v);
    return dq;
}

TEST(Node, New)
{
    t_int_list* l = list_new(69);

    ASSERT_TRUE(l != nullptr);
    ASSERT_TRUE(l->val == 69);
    ASSERT_TRUE(l->next == nullptr);
    ASSERT_TRUE(l->prev == nullptr);
}

TEST(Deque, New)
{
    t_int_deque dq = deque_new();

    ASSERT_TRUE(dq.head == nullptr);
    ASSERT_TRUE(dq.tail == nullptr);
    ASSERT_TRUE(dq.sz == 0);
}

TEST(Deque, PeekEmpty)
{
    t_int_deque dq = deque_new();

    const t_int_list* head = deque_peek_front(dq);
    const t_int_list* tail = deque_peek_back(dq);

    ASSERT_TRUE(head == nullptr);
    ASSERT_TRUE(tail == nullptr);
}

TEST(Deque, PopEmpty)
{
    t_int_deque dq = deque_new();

    const t_int_list* head = deque_peek_front(dq);
    ASSERT_TRUE(head == nullptr);

    dq = deque_new();
    const t_int_list* tail = deque_peek_back(dq);

    ASSERT_TRUE(tail == nullptr);
}

TEST(Deque, Pop)
{
    t_int_deque dq = deque_new();
    deque_push_back(&dq, 0);
    deque_push_back(&dq, 1);
    deque_push_back(&dq, 2);
    deque_push_back(&dq, 3);
    assert_deque_eq(dq, {0, 1, 2, 3});

    ASSERT_TRUE(deque_pop_front(&dq)->val == 0);
    assert_deque_eq(dq, {1, 2, 3});

    ASSERT_TRUE(deque_pop_back(&dq)->val == 3);
    assert_deque_eq(dq, {1, 2});

    ASSERT_TRUE(deque_pop_front(&dq)->val == 1);
    assert_deque_eq(dq, {2});

    ASSERT_TRUE(deque_pop_front(&dq)->val == 2);
    ASSERT_TRUE(deque_is_empty(dq));
}

TEST(Deque, PushFrontLink)
{
    t_int_deque dq = deque_new();

    deque_push_front_link(&dq, list_new(420));
    assert_deque_eq(dq, {420});

    deque_push_front_link(&dq, list_new(-1));
    assert_deque_eq(dq, {-1, 420});

    deque_push_front_link(&dq, list_new(69));
    assert_deque_eq(dq, {69, -1, 420});
}

TEST(Deque, PushBackLink)
{
    t_int_deque dq = deque_new();

    deque_push_back_link(&dq, list_new(0));
    assert_deque_eq(dq, {0});

    deque_push_back_link(&dq, list_new(420));
    assert_deque_eq(dq, {0, 420});

    deque_push_back_link(&dq, list_new(69));
    assert_deque_eq(dq, {0, 420, 69});
}

TEST(Deque, PushFront)
{
    t_int_deque dq = deque_new();

    deque_push_front(&dq, 420);
    assert_deque_eq(dq, {420});

    deque_push_front(&dq, -1);
    assert_deque_eq(dq, {-1, 420});

    deque_push_front(&dq, 69);
    assert_deque_eq(dq, {69, -1, 420});
}

TEST(Deque, PushBack)
{
    t_int_deque dq = deque_new();

    deque_push_back(&dq, 0);
    assert_deque_eq(dq, {0});

    deque_push_back(&dq, 420);
    assert_deque_eq(dq, {0, 420});

    deque_push_back(&dq, 69);
    assert_deque_eq(dq, {0, 420, 69});
}

TEST(Deque, Clear)
{
    t_int_deque dq = deque_new();
    ASSERT_TRUE(deque_is_empty(dq));

    deque_push_back(&dq, 69);
    deque_push_back(&dq, 69);
    deque_push_back(&dq, 69);
    deque_push_back(&dq, 69);
    deque_push_back(&dq, 69);
    assert_deque_eq(dq, {69, 69, 69, 69, 69});
    ASSERT_FALSE(deque_is_empty(dq));

    deque_clear(&dq);
    ASSERT_TRUE(deque_is_empty(dq));
}

TEST(Deque, DeepCopy)
{
    Vector src_vec = {1, 2, 3, 4, 5};
    t_int_deque src_dq = deque_from_vec(src_vec);
    assert_deque_eq(src_dq, src_vec);

    t_int_deque copy = deque_deep_copy(src_dq);
    ASSERT_NE(src_dq.head, copy.head);
    ASSERT_NE(src_dq.tail, copy.tail);
    assert_deque_eq(copy, src_vec);
}

TEST(Deque, FindMin)
{
    Vector src = {69, 420, 0, -42, 69};
    t_int_deque dq = deque_from_vec(src);
    assert_deque_eq(dq, src);
    ASSERT_EQ(deque_find_min(&dq), 3);
    deque_clear(&dq);

    src = {5, 4, 3, 2, 1, 0};
    dq = deque_from_vec(src);
    assert_deque_eq(dq, src);
    ASSERT_EQ(deque_find_min(&dq), 5);
    deque_clear(&dq);

    dq = deque_new();
    ASSERT_EQ(deque_find_min(&dq), -1);
}
