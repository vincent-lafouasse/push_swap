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

const char* I32_MIN_STR = "-2147483648";
const char* I32_MAX_STR = "2147483647";
const char* U32_MAX_STR = "4294967295";

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

    opt = checked_atou(I32_MAX_STR);
    assert_opt_ok(opt, INT32_MAX);
    
    opt = checked_atou(U32_MAX_STR);
    assert_opt_ok(opt, UINT32_MAX);
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

    opt = checked_atou(I32_MIN_STR);
    assert_opt_none(opt);

    opt = checked_atou("");
    assert_opt_none(opt);

    opt = checked_atou("042");
    assert_opt_none(opt);
}

TEST(AtoU, Overflow)
{
    t_opt_uint opt;

    opt = checked_atou("4294967296"); // U32_MAX + 1
    assert_opt_none(opt);

    opt = checked_atou("4294967305"); // U32_MAX + 10
    assert_opt_none(opt);

    opt = checked_atou("9994967305"); // same n digits but bigger
    assert_opt_none(opt);

    opt = checked_atou("429496729600"); // more digits
    assert_opt_none(opt);
}

TEST(AtoI, Valid)
{
    t_opt_int opt;

    opt = checked_atoi("0");
    assert_opt_ok(opt, 0);

    opt = checked_atoi("1");
    assert_opt_ok(opt, 1);

    opt = checked_atoi("69");
    assert_opt_ok(opt, 69);

    opt = checked_atoi("420");
    assert_opt_ok(opt, 420);

    opt = checked_atoi(I32_MAX_STR);
    assert_opt_ok(opt, INT32_MAX);

    opt = checked_atoi(I32_MIN_STR);
    assert_opt_ok(opt, INT32_MIN);

    opt = checked_atoi("-420");
    assert_opt_ok(opt, -420);
}


TEST(AtoI, NotANumber)
{
    t_opt_int opt;

    opt = checked_atoi("salut");
    assert_opt_none(opt);

    opt = checked_atoi("one");
    assert_opt_none(opt);

    opt = checked_atoi(" 1 ");
    assert_opt_none(opt);

    opt = checked_atoi("");
    assert_opt_none(opt);

    opt = checked_atoi("042");
    assert_opt_none(opt);
}
