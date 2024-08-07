#include "gtest/gtest.h"

extern "C"
{
#include "load/load_internals.h"
};

static void assert_opt_ok(t_opt_uint opt, t_u32 val)
{
    ASSERT_TRUE(opt.is_valid);
    ASSERT_TRUE(opt.val == val);
}

static void assert_opt_ok(t_opt_int opt, t_i32 val)
{
    ASSERT_TRUE(opt.is_valid);
    ASSERT_TRUE(opt.val == val);
}

static void assert_opt_none(t_opt_uint opt)
{
    ASSERT_FALSE(opt.is_valid);
}

static void assert_opt_none(t_opt_int opt)
{
    ASSERT_FALSE(opt.is_valid);
}

TEST(AtoU, Valid)
{
    t_opt_uint opt;

    opt = checked_atou("0");
    assert_opt_ok(opt, 0);

    opt = checked_atou("1");
    assert_opt_ok(opt, 1);

    opt = checked_atou("69");
    assert_opt_ok(opt, 69);

    opt = checked_atou("420");
    assert_opt_ok(opt, 420);
}
