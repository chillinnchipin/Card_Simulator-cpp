#include <string>
using namespace std;

namespace cardsim
{
    namespace objects
    {
        class Card
        {
            private:
            // Attributes
            /// @brief the suit of the card
            string suit;

            /// @brief the numerical value held by the card
            int value;

            public:
            // Constructors

            /**
             * @brief a default contructor that initalizes an empty suit and value
             */
            Card();

            /**
             * @brief a constructor that initalizes both the suit and value of the card
             * 
             * @param suit the suit of the card
             * @param value the value of the card
             */
            Card(string suit, int value) : suit(suit), value(value) {}

            // Methods

            /**
             * @brief returns the suit of the card
             *
             * @return the suit of the card
             */
            string get_suit();

            /**
             * @brief returns the value of the card
             *
             * @return the value of the card
             */
            int get_value();

            /**
             * @brief sets the suit of the card to the given suit
             *
             * @param suit the new suit to set the card to
             */
            void set_suit(string suit);

            /**
             * @brief sets the value of the card to the given value
             *
             * @param value the new value to set the card to
             */
            void set_value(int value);

            // Operators

            /**
             * @brief set the card to the given card
             *
             * @param other the other card to change the card to
             * @return a copy reference to the card
             */
            Card &operator=(Card other);

            /**
             * @brief sets the value to the given integer
             *
             * @param other the integer to set the value to
             * @return a copy reference to the card
             */
            Card &operator=(int other);

            /**
             * @brief sets the suit to the given string
             *
             * @param other the string to set the suit to
             * @return a copy reference to the card
             */
            Card &operator=(string other);

            /**
             * @brief adds the value of the other card if they have the same suit
             *
             * @param other the card to add the value from
             * @return a copy reference to the card
             */
            Card &operator+(Card other);

            /**
             * @brief adds the given value to the card's value
             *
             * @param other the integer to add to the card's value
             * @return a copy reference to the card
             */
            Card &operator+(int other);

            /**
             * @brief returns true if both cards have the same suit and value, returns false otherwise
             *
             * @param other the other card to compare to suit and value to
             * @return true if both cards' suits and values are equal, false otherwise
             */
            bool operator==(Card other);

            /**
             * @brief returns true if value if less than ther value of the other card, returns false otherwise
             *
             * @param other the other card to compare to suit and value to
             * @return true if the value is less than ther other card's value, false otherwise
             */
            bool operator<(Card other);

            /**
             * @brief returns true if value is greater than the other card's value, returns false otherwise
             *
             * @param other the other card to compare to suit and value to
             * @return true if the value is greather than ther other card's value, false otherwise
             */
            bool operator>(Card other);
        };

        class PlayingCard : Card
        {
        public:
            /// @brief a class limiting the Suit attribute to: Clubs, Diamonds, Hearts, Spades
            enum class Suit
            {
                CLubs,
                Diamonds,
                Hearts,
                Spades,
            };
            
            /// @brief a classs limiting the Value attribute to: "Jack", "Queen", "King", "Ace", and 1-10
            enum class Value {
                One,
                Two,
                Three,
                Four,
                Five,
                Six,
                Seven,
                Eight,
                Nine,
                Ten,
                Jack,
                Queen,
                King,
                Ace,
            };

        private:
            /// @brief the suit of the card, limited to: Clubs, Diamonds, Hearts, Spades
            Suit suit;
            /// @brief the value of the card, limited to: "Jack", "Queen", "King", "Ace", and 1-10
            Value value;

        public:

            /**
             * @brief a constructor that initalize the suit and value of the card
             * 
             * @param suit the suit to set the card to, options are limited to: "Diamonds", "Clubs", "Hearts", "Spades"
             * @param value the value to set the card to, options are limited to: "Jack", "Queen", "King", "Ace", and 1-10
             */
            PlayingCard(Suit suit, Value value);
            /**
             * @brief returns the suit of the card
             * 
             * @return the suit of the card
             */
            Suit get_suit();

            /**
             * @brief returns the value of the card
             * 
             * @return the value of the card
             */
            Value get_value();

            /**
             * @brief sets the suit of the card to the given suit
             * 
             * @param suit the new suit to set the card to
             */
            void set_suit(Suit suit);

            /**
             * @brief sets the value of the card to the given value
             * 
             * @param value the new value to set the card to
             */
            void set_value(Value value);
        };
    }
}