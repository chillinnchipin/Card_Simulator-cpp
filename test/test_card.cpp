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

void test_Card_operator_assign() {
    // Create original card
    std::string original_suit = "Hearts";
    int original_value = 5;
    cardsim::objects::Card original_card = cardsim::objects::Card(original_suit, original_value);

    // Create new card with different suit and value
    std::string new_suit = "Diamonds";
    int new_value = 10;
    cardsim::objects::Card new_card = cardsim::objects::Card(new_suit, new_value);

    // Assign new card to original card
    original_card = new_card;
    CU_ASSERT_EQUAL(original_card.get_suit(), new_suit);
    CU_ASSERT_EQUAL(original_card.get_value(), new_value);
    CU_ASSERT_NOT_EQUAL(original_card.get_suit(), original_suit);
    CU_ASSERT_NOT_EQUAL(original_card.get_value(), original_value);
}

void test_Card_operator_add() {
    // Create original card
    std::string original_suit = "Hearts";
    int original_value = 5;
    cardsim::objects::Card original_card = cardsim::objects::Card(original_suit, original_value);

    // Create another card with the same suit and a different value
    std::string other_suit = "Hearts";
    int other_value = 10;
    cardsim::objects::Card other_card = cardsim::objects::Card(other_suit, other_value);

    // Add the other card to the original card
    original_card + other_card;

    // Assert that the value of the original card has been updated correctly
    CU_ASSERT_EQUAL(original_card.get_value(), original_value + other_value);

    // Add an additional value to the original card
    int additional_value = 3;
    original_card + additional_value;
    CU_ASSERT_EQUAL(original_card.get_value(), original_value + other_value + additional_value);
}

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

void test_PlayingCard_default_constructor() {
    // TODO add default constructor
    //CU_FAIL("TODO test: no default constructor exist to test");
    /*
    // Create default object
    cardsim::objects::PlayingCard test_card = cardsim::objects::PlayingCard();

    // Asserts values are empty
    CU_ASSERT_EQUAL(test_card.get_suit(), cardsim::objects::PlayingCard::Suit::CLubs); // Assuming default suit is Clubs
    CU_ASSERT_EQUAL(test_card.get_value(), cardsim::objects::PlayingCard::Value::One); // Assuming default value is One */
}

void test_PlayingCard_constructor() {
    // Set test values
    cardsim::objects::PlayingCard::Suit suit = cardsim::objects::PlayingCard::Suit::Hearts;
    cardsim::objects::PlayingCard::Value value = cardsim::objects::PlayingCard::Value::Ace;

    // Create card object
    cardsim::objects::PlayingCard test_card = cardsim::objects::PlayingCard(suit, value);

    // Assert card values are the same
    CU_ASSERT_EQUAL(test_card.get_suit(), suit);
    CU_ASSERT_EQUAL(test_card.get_value(), value);
}

void test_PlayingCard_get_suit() {
    // Set testing values
    // TODO make a test fixture for this
    cardsim::objects::PlayingCard::Suit expected_suit = cardsim::objects::PlayingCard::Suit::Diamonds;
    cardsim::objects::PlayingCard::Value value = cardsim::objects::PlayingCard::Value::One;

    // Create test objects
    cardsim::objects::PlayingCard test_card = cardsim::objects::PlayingCard(expected_suit, value);

    // Test function
    auto actual_suit = test_card.get_suit();

    // Assert actual == expected
    CU_ASSERT_EQUAL(actual_suit, expected_suit);
}

void test_PlayingCard_get_value() {
    // Set testing values
    // TODO make a test fixture for this
    cardsim::objects::PlayingCard::Suit suit = cardsim::objects::PlayingCard::Suit::Diamonds;
    cardsim::objects::PlayingCard::Value expected_value = cardsim::objects::PlayingCard::Value::One;

    // Create test objects
    cardsim::objects::PlayingCard test_card = cardsim::objects::PlayingCard(suit, expected_value);

    // Test function
    auto actual_value = test_card.get_value();

    // Assert actual == expected
    CU_ASSERT_EQUAL(actual_value, expected_value);
}

void test_PlayingCard_set_suit() {
    // Set testing values
    // TODO make a test fixture for this
    cardsim::objects::PlayingCard::Suit suit = cardsim::objects::PlayingCard::Suit::Diamonds;
    cardsim::objects::PlayingCard::Value value = cardsim::objects::PlayingCard::Value::One;
    cardsim::objects::PlayingCard::Suit new_suit = cardsim::objects::PlayingCard::Suit::Hearts;

    // Create test objects
    cardsim::objects::PlayingCard test_card = cardsim::objects::PlayingCard(suit, value);

    // Test function
    test_card.set_suit(new_suit);

    // Assert current == new
    auto actual_suit = test_card.get_suit();
    CU_ASSERT_EQUAL(actual_suit, new_suit);
    CU_ASSERT_NOT_EQUAL(actual_suit, suit);
}

void test_PlayingCard_set_value() {
    // Set testing values
    // TODO make a test fixture for this
    cardsim::objects::PlayingCard::Suit suit = cardsim::objects::PlayingCard::Suit::Diamonds;
    cardsim::objects::PlayingCard::Value value = cardsim::objects::PlayingCard::Value::One;
    cardsim::objects::PlayingCard::Value new_value = cardsim::objects::PlayingCard::Value::Ace;

    // Create test objects
    cardsim::objects::PlayingCard test_card = cardsim::objects::PlayingCard(suit, value);

    // Test function
    test_card.set_value(new_value);

    // Assert current == new
    auto actual_value = test_card.get_value();
    CU_ASSERT_EQUAL(actual_value, new_value);
    CU_ASSERT_NOT_EQUAL(actual_value, value);
}

void test_PlayingCard_int_to_suit() {
    // Assert Clubs
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::int_to_suit(0), cardsim::objects::PlayingCard::Suit::CLubs);
    // Assert Diamonds
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::int_to_suit(1), cardsim::objects::PlayingCard::Suit::Diamonds);
    // Assert Hearts
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::int_to_suit(2), cardsim::objects::PlayingCard::Suit::Hearts);
    // Assert Spades
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::int_to_suit(3), cardsim::objects::PlayingCard::Suit::Spades);
}

void test_PlayingCard_string_to_suit() {
    // Assert Clubs
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::string_to_suit("Clubs"), cardsim::objects::PlayingCard::Suit::CLubs);
    // Assert Diamonds
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::string_to_suit("Diamonds"), cardsim::objects::PlayingCard::Suit::Diamonds);
    // Assert Hearts
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::string_to_suit("Hearts"), cardsim::objects::PlayingCard::Suit::Hearts);
    // Assert Spades
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::string_to_suit("Spades"), cardsim::objects::PlayingCard::Suit::Spades);
}

void test_PlayingCard_int_to_value() {
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::int_to_value(0), cardsim::objects::PlayingCard::Value::Ace);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::int_to_value(1), cardsim::objects::PlayingCard::Value::One);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::int_to_value(2), cardsim::objects::PlayingCard::Value::Two);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::int_to_value(3), cardsim::objects::PlayingCard::Value::Three);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::int_to_value(4), cardsim::objects::PlayingCard::Value::Four);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::int_to_value(5), cardsim::objects::PlayingCard::Value::Five);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::int_to_value(6), cardsim::objects::PlayingCard::Value::Six);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::int_to_value(7), cardsim::objects::PlayingCard::Value::Seven);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::int_to_value(8), cardsim::objects::PlayingCard::Value::Eight);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::int_to_value(9), cardsim::objects::PlayingCard::Value::Nine);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::int_to_value(10), cardsim::objects::PlayingCard::Value::Ten);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::int_to_value(11), cardsim::objects::PlayingCard::Value::Queen);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::int_to_value(12), cardsim::objects::PlayingCard::Value::King);
}

void test_PlayingCard_string_to_value() {
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::string_to_value("Ace"), cardsim::objects::PlayingCard::Value::Ace);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::string_to_value("One"), cardsim::objects::PlayingCard::Value::One);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::string_to_value("Two"), cardsim::objects::PlayingCard::Value::Two);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::string_to_value("Three"), cardsim::objects::PlayingCard::Value::Three);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::string_to_value("Four"), cardsim::objects::PlayingCard::Value::Four);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::string_to_value("Five"), cardsim::objects::PlayingCard::Value::Five);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::string_to_value("Six"), cardsim::objects::PlayingCard::Value::Six);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::string_to_value("Seven"), cardsim::objects::PlayingCard::Value::Seven);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::string_to_value("Eight"), cardsim::objects::PlayingCard::Value::Eight);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::string_to_value("Nine"), cardsim::objects::PlayingCard::Value::Nine);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::string_to_value("Ten"), cardsim::objects::PlayingCard::Value::Ten);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::string_to_value("Queen"), cardsim::objects::PlayingCard::Value::Queen);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::string_to_value("King"), cardsim::objects::PlayingCard::Value::King);
}

void test_PlayingCard_suit_to_int() {
    // Assert Clubs
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::suit_to_int(cardsim::objects::PlayingCard::Suit::CLubs), 0);
    // Assert Diamonds
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::suit_to_int(cardsim::objects::PlayingCard::Suit::Diamonds), 1);
    // Assert Hearts
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::suit_to_int(cardsim::objects::PlayingCard::Suit::Hearts), 2);
    // Assert Spades
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::suit_to_int(cardsim::objects::PlayingCard::Suit::Spades), 3);
}

void test_PlayingCard_suit_to_string() {
    // Assert Clubs
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::suit_to_string(cardsim::objects::PlayingCard::Suit::CLubs), "Clubs");
    // Assert Diamonds
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::suit_to_string(cardsim::objects::PlayingCard::Suit::Diamonds), "Diamonds");
    // Assert Hearts
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::suit_to_string(cardsim::objects::PlayingCard::Suit::Hearts), "Hearts");
    // Assert Spades
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::suit_to_string(cardsim::objects::PlayingCard::Suit::Spades), "Spades");
}

void test_PlayingCard_value_to_int() {
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_int(cardsim::objects::PlayingCard::Value::Ace), 0);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_int(cardsim::objects::PlayingCard::Value::One), 1);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_int(cardsim::objects::PlayingCard::Value::Two), 2);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_int(cardsim::objects::PlayingCard::Value::Three), 3);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_int(cardsim::objects::PlayingCard::Value::Four), 4);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_int(cardsim::objects::PlayingCard::Value::Five), 5);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_int(cardsim::objects::PlayingCard::Value::Six), 6);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_int(cardsim::objects::PlayingCard::Value::Seven), 7);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_int(cardsim::objects::PlayingCard::Value::Eight), 8);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_int(cardsim::objects::PlayingCard::Value::Nine), 9);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_int(cardsim::objects::PlayingCard::Value::Ten), 10);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_int(cardsim::objects::PlayingCard::Value::Queen), 11);
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_int(cardsim::objects::PlayingCard::Value::King), 12);
}

void test_PlayingCard_value_to_string() {
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_string(cardsim::objects::PlayingCard::Value::Ace), "Ace");
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_string(cardsim::objects::PlayingCard::Value::One), "One");
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_string(cardsim::objects::PlayingCard::Value::Two), "Two");
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_string(cardsim::objects::PlayingCard::Value::Three), "Three");
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_string(cardsim::objects::PlayingCard::Value::Four), "Four");
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_string(cardsim::objects::PlayingCard::Value::Five), "Five");
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_string(cardsim::objects::PlayingCard::Value::Six), "Six");
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_string(cardsim::objects::PlayingCard::Value::Seven), "Seven");
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_string(cardsim::objects::PlayingCard::Value::Eight), "Eight");
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_string(cardsim::objects::PlayingCard::Value::Nine), "Nine");
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_string(cardsim::objects::PlayingCard::Value::Ten), "Ten");
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_string(cardsim::objects::PlayingCard::Value::Queen), "Queen");
    CU_ASSERT_EQUAL(cardsim::objects::PlayingCard::value_to_string(cardsim::objects::PlayingCard::Value::King), "King");
}
