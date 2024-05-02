/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(GuesserTest, set_and_check)
{
	Guesser my_guesser("hello");
	bool actual = my_guesser.match("hello");
    ASSERT_EQ(true, actual);
}

TEST(GuesserTest, long_set_and_check)
{
	Guesser my_guesser("hellothisismorethan32characters!!!!!!!");
	bool actual = my_guesser.match("hellothisismorethan32characters!");
    ASSERT_EQ(true, actual);
}

TEST(GuesserTest, wrong_once_check_remaining)
{
	Guesser my_guesser("hello");
	my_guesser.match("Hello");
	int actual = my_guesser.remaining();
    ASSERT_EQ(2, actual);
}

TEST(GuesserTest, wrong_once_check_bool)
{
	Guesser my_guesser("hello");
	bool actual = my_guesser.match("Hello");
    ASSERT_EQ(false, actual);
}

TEST(GuesserTest, wrong_once_then_right_remaining)
{
	Guesser my_guesser("hello");
	my_guesser.match("Hello");
	my_guesser.match("hello");
	int actual = my_guesser.remaining();
    ASSERT_EQ(3, actual);
}

TEST(GuesserTest, wrong_once_then_right_bool)
{
	Guesser my_guesser("hello");
	my_guesser.match("Hello");
	bool actual = my_guesser.match("hello");
    ASSERT_EQ(true, actual);
}

TEST(GuesserTest, wrong_twice_then_right_remaining)
{
	Guesser my_guesser("hello");
	my_guesser.match("Hello");
	my_guesser.match("Hello");
	my_guesser.match("hello");
	int actual = my_guesser.remaining();
    ASSERT_EQ(3, actual);
}

TEST(GuesserTest, wrong_twice_then_right_bool)
{
	Guesser my_guesser("hello");
	my_guesser.match("Hello");
	my_guesser.match("Hello");
	bool actual = my_guesser.match("hello");
    ASSERT_EQ(true, actual);
}

TEST(GuesserTest, wrong_thrice_then_right_remaining)
{
	Guesser my_guesser("hello");
	my_guesser.match("Hello");
	my_guesser.match("Hello");
	my_guesser.match("Hello");
	my_guesser.match("hello");
	int actual = my_guesser.remaining();
    ASSERT_EQ(0, actual);
}

TEST(GuesserTest, wrong_thrice_then_right_bool)
{
	Guesser my_guesser("hello");
	my_guesser.match("Hello");
	my_guesser.match("Hello");
	my_guesser.match("Hello");
	bool actual = my_guesser.match("hello");
    ASSERT_EQ(false, actual);
}

TEST(GuesserTest, wrong_twice_check_bool)
{
	Guesser my_guesser("hello");
	my_guesser.match("hello!");
	bool actual = my_guesser.match("Hello");
    ASSERT_EQ(false, actual);
}

TEST(GuesserTest, wrong_twice_check_remaining)
{
	Guesser my_guesser("hello");
	my_guesser.match("hello!");
	my_guesser.match("Hello");
	int actual = my_guesser.remaining();
    ASSERT_EQ(1, actual);
}

TEST(GuesserTest, wrong_thrice_check_bool)
{
	Guesser my_guesser("hello");
	my_guesser.match("hello!");
	my_guesser.match("hello!!");
	bool actual = my_guesser.match("Hello");
    ASSERT_EQ(false, actual);
}

TEST(GuesserTest, wrong_thrice_check_remaining)
{
	Guesser my_guesser("hello");
	my_guesser.match("hello!");
	my_guesser.match("Hello");
	my_guesser.match("hello!!");
	int actual = my_guesser.remaining();
    ASSERT_EQ(0, actual);
}

TEST(GuesserTest, wrong_four_check_bool)
{
	Guesser my_guesser("hello");
	my_guesser.match("hello!");
	my_guesser.match("hello!!");
	my_guesser.match("hello!!");
	bool actual = my_guesser.match("Hello");
    ASSERT_EQ(false, actual);
}

TEST(GuesserTest, wrong_four_check_remaining)
{
	Guesser my_guesser("hello");
	my_guesser.match("hello!");
	my_guesser.match("Hello");
	my_guesser.match("hello!!");
	my_guesser.match("hello!!");
	int actual = my_guesser.remaining();
    ASSERT_EQ(0, actual);
}

TEST(GuesserTest, wrong_once_large_dist_check_bool)
{
	Guesser my_guesser("hello");
	bool actual = my_guesser.match("howdyyall");
    ASSERT_EQ(false, actual);
}

TEST(GuesserTest, wrong_once_large_dist_check_remaining)
{
	Guesser my_guesser("hello");
	my_guesser.match("howdyyall");
	int actual = my_guesser.remaining();
    ASSERT_EQ(2, actual);
}

TEST(GuesserTest, wrong_once_large_dist_2_tries_bool)
{
	Guesser my_guesser("hello");
	my_guesser.match("howdyyall");
	bool actual = my_guesser.match("hello");
    ASSERT_EQ(false, actual);
}

TEST(GuesserTest, wrong_once_large_dist_1_tries_remaining)
{
	Guesser my_guesser("hello");
	my_guesser.match("howdyyall");
	my_guesser.match("hello");
	int actual = my_guesser.remaining();
    ASSERT_EQ(1, actual);
}

TEST(GuesserTest, wrong_once_large_dist_no_try_remaining)
{
	Guesser my_guesser("hello");
	my_guesser.match("howdyyall");
	my_guesser.match("hello");
	my_guesser.match("hello");
	int actual = my_guesser.remaining();
    ASSERT_EQ(0, actual);
}

TEST(GuesserTest, guess_too_short)
{
	Guesser my_guesser("hello");
	my_guesser.match("hi");
	int actual = my_guesser.remaining();
    ASSERT_EQ(2, actual);
}

TEST(GuesserTest, guess_too_short_bool)
{
	Guesser my_guesser("hello");
	bool actual = my_guesser.match("hell");
    ASSERT_EQ(false, actual);
}

TEST(GuesserTest, completely_wrong_guess)
{
	Guesser my_guesser("hello");
	bool actual = my_guesser.match("abcde");
    ASSERT_EQ(false, actual);
}

TEST(GuesserTest, initial_state)
{
	Guesser my_guesser("hello");
	int actual = my_guesser.remaining();
    ASSERT_EQ(3, actual);
}

TEST(GuesserTest, another_wrong_guess)
{
	Guesser my_guesser("hello");
	bool actual = my_guesser.match("hel1o");
    ASSERT_EQ(false, actual);
}

TEST(GuesserTest, another_wrong_guess_remaining)
{
	Guesser my_guesser("hello");
	my_guesser.match("hel1o");
	int actual = my_guesser.remaining();
    ASSERT_EQ(2, actual);
}