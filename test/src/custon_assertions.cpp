#include "custom_assertions.h"

#include "gtest/gtest.h"

void assert_deque_eq(const t_int_deque dq, const std::vector<int>& expected)
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
