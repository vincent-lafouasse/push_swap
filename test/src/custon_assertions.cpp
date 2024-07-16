#include "custom_assertions.h"

#include "gtest/gtest.h"

void assert_deque_eq(const t_int_deque dq, const std::vector<int>& expected)
{
    ASSERT_TRUE(dq.sz == expected.size()) << "Error, invalid size. expected size " << expected.size() << " was " << dq.sz;

    t_int_list* current = dq.head;
    size_t i {};

    while (current && i < expected.size())
    {
        ASSERT_TRUE(current->val == expected[i]) << "Error, expected " << expected[i] <<" was " << current->val;
        i++;
        current = current->next;
    }
    //ASSERT_TRUE(current == nullptr);
    //ASSERT_TRUE(i == expected.size());
}
