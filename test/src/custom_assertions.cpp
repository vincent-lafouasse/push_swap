#include "custom_assertions.h"

#include "gtest/gtest.h"

void assert_deque_eq(const t_int_deque dq, const std::vector<int>& expected)
{
    EXPECT_EQ(dq.sz, expected.size())
        << "Error, invalid size. expected size " << expected.size() << " was "
        << dq.sz;

    t_int_list* current = dq.head;
    size_t i{};

    while (current && i < expected.size())
    {
        EXPECT_EQ(current->val, expected[i])
            << "Error, expected " << expected[i] << " was " << current->val;
        i++;
        current = current->next;
    }
    ASSERT_EQ(current, nullptr);
    ASSERT_EQ(i, expected.size());
}
