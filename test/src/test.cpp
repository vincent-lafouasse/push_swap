#include "gtest/gtest.h"

extern "C"
{
#include "deque/t_int_deque.h"
};

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
    ASSERT_TRUE(dq.head->val == 420);
    ASSERT_TRUE(dq.tail->val == 420);
    ASSERT_TRUE(dq.sz == 1);

    deque_push_front_link(&dq, list_new(-1));
    ASSERT_TRUE(dq.head->val == -1);
    ASSERT_TRUE(dq.tail->val == 420);
    ASSERT_TRUE(dq.sz == 2);

    deque_push_front_link(&dq, list_new(69));
    ASSERT_TRUE(dq.head->val == 69);
    ASSERT_TRUE(dq.tail->val == 420);
    ASSERT_TRUE(dq.sz == 3);
}

TEST(Deque, PushBackLink)
{
    t_int_deque dq = deque_new();

    deque_push_back_link(&dq, list_new(0));
    ASSERT_TRUE(dq.head->val == 0);
    ASSERT_TRUE(dq.tail->val == 0);
    ASSERT_TRUE(dq.sz == 1);

    deque_push_back_link(&dq, list_new(420));
    ASSERT_TRUE(dq.head->val == 0);
    ASSERT_TRUE(dq.tail->val == 420);
    ASSERT_TRUE(dq.sz == 2);

    deque_push_back_link(&dq, list_new(69));
    ASSERT_TRUE(dq.head->val == 0);
    ASSERT_TRUE(dq.tail->val == 69);
    ASSERT_TRUE(dq.sz == 3);
}

TEST(Deque, PushFront)
{
    t_int_deque dq = deque_new();

    deque_push_front(&dq, 420);
    ASSERT_TRUE(dq.head->val == 420);
    ASSERT_TRUE(dq.tail->val == 420);
    ASSERT_TRUE(dq.sz == 1);

    deque_push_front(&dq, -1);
    ASSERT_TRUE(dq.head->val == -1);
    ASSERT_TRUE(dq.tail->val == 420);
    ASSERT_TRUE(dq.sz == 2);

    deque_push_front(&dq, 69);
    ASSERT_TRUE(dq.head->val == 69);
    ASSERT_TRUE(dq.tail->val == 420);
    ASSERT_TRUE(dq.sz == 3);
}

TEST(Deque, PushBack)
{
    t_int_deque dq = deque_new();

    deque_push_back(&dq, 0);
    ASSERT_TRUE(dq.head->val == 0);
    ASSERT_TRUE(dq.tail->val == 0);
    ASSERT_TRUE(dq.sz == 1);

    deque_push_back(&dq, 420);
    ASSERT_TRUE(dq.head->val == 0);
    ASSERT_TRUE(dq.tail->val == 420);
    ASSERT_TRUE(dq.sz == 2);

    deque_push_back(&dq, 69);
    ASSERT_TRUE(dq.head->val == 0);
    ASSERT_TRUE(dq.tail->val == 69);
    ASSERT_TRUE(dq.sz == 3);
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
    ASSERT_FALSE(deque_is_empty(dq));

    deque_clear(&dq);
    ASSERT_TRUE(deque_is_empty(dq));
}
