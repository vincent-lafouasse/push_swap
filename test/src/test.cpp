#include "gtest/gtest.h"

extern "C" {
#include "t_int_deque.h"
};

TEST(Deque, New) {
  t_int_deque dq = deque_new();

  ASSERT_TRUE(dq.head == NULL);
  ASSERT_TRUE(dq.tail == NULL);
  FAIL();
}
