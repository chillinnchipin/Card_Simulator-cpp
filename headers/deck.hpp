#include <stdlib.h>
#include <vector>
#include <array>
#include <optional>
#include <iterator>

#include "card.hpp"

namespace cardsim
{
    namespace objects
    {
        class Deck
        {
        private:
            // Attributes

            /// @brief the size of the deck, the number of cards in the deck
            size_t deck_size;

            /// @brief a list of cards in the deck
            std::vector<Card> deck;

        public:
            // Constructors

            /**
             * @brief a default constructor that initalizes the deck with no cards and a size of 0
             */
            Deck();

            /**
             * @brief a constructor that takes an array of cards and adds all the cards to the deck
             *
             * @param deck the array of all cards to add to the deck
             * @param size the size of the array deck
             */
            Deck(Card deck[], size_t size);

            // TODO constructor that takes std::array as a deck of cards

            /**
             * @brief constructor that takes a vector containing all the cards to be added to the deck
             *
             * @param deck the vector of cards to add to the deck
             */
            Deck(std::vector<Card> deck);

            // Methods

            /**
             * @brief returns the size of the deck, i.e. number of cards in the deck
             * 
             * @return the number of cards in the deck
             */
            size_t size();

            /**
             * @brief used to tell if the deck is empty or not
             * 
             * @return true if there are not card in the deck, false if there is at least one card in the deck
             */
            bool empty();

            /**
             * @brief 
             * 
             * @return an iterator for the first card in the deck
             */
            std::vector<Card>::iterator begin();

            /**
             * @brief 
             * 
             * @return an iterator for the last card in the deck
             */
            std::vector<Card>::iterator end();

            /**
             * @brief returns the deck of cards as a list of cards
             *
             * @param deck the array to be filled with all of the cards in the deck
             * @param size an optional pointer to a size variable to store the number of items in the arrray
             * @return the number of items that were added to the array
             * @note the size variable and return value will be the same when the fuction returns
             */
            size_t get_deck(Card deck[], size_t *size);

            /**
             * @brief returns the number of cards in the deck
             * 
             * @return a vector holding all the cards in the deck
             */
            std::vector<Card> get_deck();

            /**
             * @brief returns the specific card at the given index
             *
             * @param index the index of the card to retrieve
             * @return the card at the index
             */
            Card get_card(size_t index);

            /**
             * @brief returns the first card matching the given card
             *
             * @param Card 
             * @return the first card matching to the card parameter
             */
            Card get_card(Card card);

            /**
             * @brief returns the first card with the same suit and value given
             *
             * @param suit the suit of the card to retrieve
             * @param value the value of the card to retrieve
             * @return the first card with the same suit and value as given
             */
            Card get_card(string suit, int value);

            /**
             * @brief fills the array with all cards with that match the given card
             *
             * @param deck the array to fill with all matching cards to 
             * @param size a pointer to a size variable which will be changed to the number of cards in the deck
             * @param match any card in the deck that is equal to this card will be added to the array
             * @return the number of cards in the array
             */
            size_t get_cards(Card deck[], size_t *size, Card match);

            /**
             * @brief returns a vector with all cards with that match the given card
             *
             * @param match any card in the deck that is equal to this card will be added to the vector
             * @return a vector containig all of the cards that match the given card
             */
            std::vector<Card> get_cards(Card match);

            /**
             * @brief fills the given array with all card that have both the given suit and value
             *
             * @param deck the array to be filled with all of the cards that have a matching suit and value
             * @param size an optional pointer to a size variable to will be changed to the number of cards in the array
             * @param suit any card that is added to the array will need to have the same suit
             * @param value any card that is added to the array will need to have the same value
             * @return
             */
            size_t get_cards(Card deck[], size_t *size, string suit, int value);

            /**
             * @brief returns all card that have both the given suit and value
             *
             * @param size an optional pointer to a size variable to will be changed to the number of cards in the vectory
             * @param suit any card that is added to the vector will need to have the same suit
             * @return a vector containing all the cards with the same suit and value 
             */
            std::vector<Card> get_cards(string suit, int value);

            /**
             * @brief changes the stored deck to the given deck
             *
             * @param deck a different instance of the deck class, stores the cards in this deck
             */
            void set_deck(Deck deck);

            /**
             * @brief changes the stored deck to the given list of cards
             *
             * @param deck an array containing all the cards to change the deck to
             * @param size the size of the array of cards
             */
            void set_deck(Card deck[], size_t size);

            /**
             * @brief changes the deck_size to the given deck size
             *
             * @param deck a vector containing all the cards to set the deck to
             */
            void set_deck(std::vector<Card> deck);

            /**
             * @brief adds the card to the deck at the given card to the given index
             *
             * @param card the card to add to the deck
             * @param index the index to add the card at
             */
            void add_card(Card card, int index);

            /**
             * @brief creates a card and adds it to the deck at the given index
             *
             * @param suit the suit of the card to add
             * @param value the value of the card to add
             * @param index the index to add the card at
             */
            void add_card(string suit, int value, size_t index);

            /**
             * @brief adds the given card to the end of the deck
             *
             * @param card the card to add to the end of the deck
             */
            void append_card(Card card);

            /**
             * @brief creates a new card and adds it to the end of the deck
             *
             * @param suit the suit of the card to add to the end of the deck
             * @param value the value of the card to add to the end of deck
             */
            void append_card(string suit, int value);

            /**
             * @brief adds the given card to the begining of the list
             *
             * @param card the card to add to the begining of the deck
             */
            void prepend_card(Card card);

            /**
             * @brief creates a new card and adds it to the begining of the deck
             *
             * @param suit the suit of the card to add to the begining of the deck
             * @param value the value of the card to add to the begining of the deck
             */
            void prepend_card(string suit, int value);

            /**
             * @brief removes the card at the given index and returns a copy of the card
             *
             * @param index the index of the card to remove
             * @return a copy of the card that was removed
             */
            Card remove_card(size_t index);

            /**
             * @brief removes the card at the end of deck and returns a coyp of the card
             *
             * @return a copy of the card that was removed
             */
            Card pop_card();

            /**
             * @brief removes the card at the begining of the deck and returns a coyp of the card
             *
             * @return a copy of the card that was removed
             */
            Card pop_head();

            /**
             * @brief returns a copy of the card at the end of the deck
             *
             * @return a copy of the card at the end of the deck
             */
            Card peak_card();

            /**
             * @brief returns a copy of the card at the begining of the deck
             *
             * @return a copy of the card at the begining of the deck
             */
            Card peak_head();

            /**
             * @brief clears all cards in the deck
             */
            void clear();

            /**
             * @brief sorts the deck using the prefered sorting algorithm in order of suits then values and returns a copy of the sorted deck
             *
             * @return a copy of the sorted deck
             */
            Deck sort();

            /**
             * @brief shuffles the deck using the prefered shuffle method and returns a copy of the shuffled deck
             *
             * @return a copy of the shuffled deck
             */
            Deck shuffle();
        };
    }
}
