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

const char* INT_MIN_STR = "-2147483648";
const char* INT_MAX_STR = "2147483647";
const char* UINT_MAX_STR = "4294967295";

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

    opt = checked_atou(INT_MAX_STR);
    assert_opt_ok(opt, 2147483647);
    
    opt = checked_atou(UINT_MAX_STR);
    assert_opt_ok(opt, 4294967295);
}

TEST(AtoU, NotANumber)
{
    t_opt_uint opt;

    opt = checked_atou("salut");
    assert_opt_none(opt);

    opt = checked_atou("one");
    assert_opt_none(opt);

    opt = checked_atou(" 1 ");
    assert_opt_none(opt);

    opt = checked_atou("-420");
    assert_opt_none(opt);

    opt = checked_atou(INT_MIN_STR);
    assert_opt_none(opt);

    opt = checked_atou("");
    assert_opt_none(opt);
}

TEST(AtoU, Overflow)
{}
