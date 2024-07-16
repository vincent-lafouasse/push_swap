#include "gtest/gtest.h"

#include <vector>

extern "C"
{
#include "deque/t_int_deque.h"
};

static void assert_deque_eq(const t_int_deque dq,
                            const std::vector<int>& expected)
{
    ASSERT_TRUE(dq.sz == expected.size());

    t_int_list* current = dq.head;
    auto it = expected.cbegin();

    while (current && it != expected.cend())
    {
        ASSERT_TRUE(current->val == *it);
        it++;
        current = current->next;
    }
    ASSERT_TRUE(current == nullptr);
    ASSERT_TRUE(it == expected.cend());
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
