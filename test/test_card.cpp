#include <CUnit/CUnit.h>
#include <CUnit/Automated.h>
#include <CUnit/Basic.h>

#include <string>
#include <array>
#include <stdlib.h>
#include <stdexcept>

#include "../headers/card.hpp"

int setup_Card_test_suite()
{
    // Setup code for the Card test suite
    return 0;
}

int cleanup_Card_test_suite()
{
    // Cleanup code for the Card test suite
    return 0;
}

void test_Card_default_constructor()
{
    // Create default object
    cardsim::objects::Card test_card = cardsim::objects::Card();

    // Assert values are the empty
    CU_ASSERT_EQUAL(test_card.get_suit(), "");
    CU_ASSERT_EQUAL(test_card.get_value(), 0);
}

void test_Card_constructor()
{
    // Set testing values
    std::string suit = "";
    int value = 0;

    // Create card object
    cardsim::objects::Card test_card = cardsim::objects::Card(suit, value);

    // Assert card values are the same
    CU_ASSERT_EQUAL(test_card.get_suit(), suit);
    CU_ASSERT_EQUAL(test_card.get_value(), value);
}

void test_Card_get_suit()
{
    // Set test values
    std::string expected_suit = "";
    int value = 0;
    std::string actual_suit;

    // Create test object
    cardsim::objects::Card test_card = cardsim::objects::Card(expected_suit, value);

    // Test function
    actual_suit = test_card.get_suit();

    // Assert actual == expected
    CU_ASSERT_EQUAL(actual_suit, expected_suit);
}

void test_Card_get_value()
{
    // Set test values
    std::string suit = "";
    int expected_value = 0;
    int actual_value;

    // Create test object
    cardsim::objects::Card test_card = cardsim::objects::Card(suit, expected_value);

    // Test function
    actual_value = test_card.get_value();

    // Assert actual == expected
    CU_ASSERT_EQUAL(actual_value, expected_value);
}

void test_Card_set_suit()
{
    // Set test values
    std::string expected_suit = "";
    int value = 0;
    std::string new_suit = "";

    // Create test object
    cardsim::objects::Card test_card = cardsim::objects::Card(expected_suit, value);

    // Test function
    test_card.set_suit(new_suit);

    // Assert actual == expected
    CU_ASSERT_EQUAL(test_card.get_suit(), new_suit);
}

void test_Card_set_value()
{
    // Set test values
    std::string suit = "";
    int expected_value = 0;
    int new_value = 0;

    // Create test object
    cardsim::objects::Card test_card = cardsim::objects::Card(suit, expected_value);

    // Test function
    test_card.set_value(new_value);

    // Assert actual == expected
    CU_ASSERT_EQUAL(test_card.get_value(), new_value);
}

void test_Card_operator_eq()
{
    // Create test object
    std::string test_suit = "";
    int test_value = 0;
    cardsim::objects::Card test_card = cardsim::objects::Card(test_suit, test_value);

    // Create equal object
    std::string equal_suit = "";
    int equal_value = 0;
    cardsim::objects::Card equal_card = cardsim::objects::Card(equal_suit, equal_value);

    // Create less than object
    std::string less_than_suit = "";
    int less_than_value = 0;
    cardsim::objects::Card less_than_card = cardsim::objects::Card(less_than_suit, less_than_value);

    // Create greater than object
    std::string greater_than_suit = "";
    int greater_than_value = 0;
    cardsim::objects::Card greater_than_card = cardsim::objects::Card(greater_than_suit, greater_than_value);

    // Test operators
    CU_ASSERT_TRUE(test_card == equal_card);

    CU_ASSERT_FALSE(test_card == less_than_card);
    CU_ASSERT_FALSE(test_card == greater_than_card);
}

void test_Card_operator_lt()
{

    // Create test object
    std::string test_suit = "";
    int test_value = 0;
    cardsim::objects::Card test_card = cardsim::objects::Card(test_suit, test_value);

    // Create equal object
    std::string equal_suit = "";
    int equal_value = 0;
    cardsim::objects::Card equal_card = cardsim::objects::Card(equal_suit, equal_value);

    // Create less than object
    std::string less_than_suit = "";
    int less_than_value = 0;
    cardsim::objects::Card less_than_card = cardsim::objects::Card(less_than_suit, less_than_value);

    // Create greater than object
    std::string greater_than_suit = "";
    int greater_than_value = 0;
    cardsim::objects::Card greater_than_card = cardsim::objects::Card(greater_than_suit, greater_than_value);

    // Test operators
    CU_ASSERT_TRUE(less_than_card < test_card);
    CU_ASSERT_TRUE(test_card < greater_than_card);

    CU_ASSERT_FALSE(test_card < less_than_card);
    CU_ASSERT_FALSE(greater_than_card < test_card);
}

void test_Card_operator_gt()
{

    // Create test object
    std::string test_suit = "";
    int test_value = 0;
    cardsim::objects::Card test_card = cardsim::objects::Card(test_suit, test_value);

    // Create equal object
    std::string equal_suit = "";
    int equal_value = 0;
    cardsim::objects::Card equal_card = cardsim::objects::Card(equal_suit, equal_value);

    // Create less than object
    std::string less_than_suit = "";
    int less_than_value = 0;
    cardsim::objects::Card less_than_card = cardsim::objects::Card(less_than_suit, less_than_value);

    // Create greater than object
    std::string greater_than_suit = "";
    int greater_than_value = 0;
    cardsim::objects::Card greater_than_card = cardsim::objects::Card(greater_than_suit, greater_than_value);

    // Test operators
    CU_ASSERT_TRUE(less_than_card > test_card);
    CU_ASSERT_TRUE(test_card > greater_than_card);

    CU_ASSERT_FALSE(test_card > less_than_card);
    CU_ASSERT_FALSE(greater_than_card > test_card);
}

void test_Card_operator_assign() {}

void test_Card_operator_add() {}

int setup_PlayingCard_test_suite()
{
    // Setup code for the Playing Card test suite
    return 0;
}

int cleanup_PlayingCard_test_suite()
{
    // Cleanup code for the Playing Card test suite
    return 0;
}

void test_PlayingCard_default_constructor() {}

void test_PlayingCard_constructor() {}

void test_PlayingCard_get_suit() {}

void test_PlayingCard_get_value() {}

void test_PlayingCard_set_suit() {}

void test_PlayingCard_set_value() {}

void test_PlayingCard_int_to_suit() {}

void test_PlayingCard_string_to_suit() {}

void test_PlayingCard_int_to_value() {}

void test_PlayingCard_string_to_value() {}
