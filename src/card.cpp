#include <string>
#include <stdexcept>

#include "../headers/card.hpp"

namespace cardsim {
    namespace objects {
        Card::Card(): suit(""), value(0) {}

        string Card::get_suit() { return suit; }

        int Card::get_value() { return value; }

        void Card::set_suit(string suit) {this->suit = suit; }

        void Card::set_value(int value) {this->value = value; }

        Card& Card::operator=(Card other) {return other; }

        Card& Card::operator=(int other) {
            value = other;
            return *this;
        }

        Card& Card::operator=(string other) {
            suit = other;
            return *this;
        }

        Card& Card::operator+(Card other) {
            value += other.get_value();
            return *this;
        }

        Card& Card::operator+(int other) {
            value += other;
            return *this;
        }

        bool Card::operator==(Card other) { return (this->suit == other.get_suit() && this->value == other.get_value()); }

        bool Card::operator<(Card other) { return (this->suit < other.get_suit() && this->value < other.get_value()); }

        bool Card::operator>(Card other) { return (this->suit > other.get_suit() && this->value > other.get_value()); }

        PlayingCard::PlayingCard(Suit suit, Value value) {
            // Type check for suit and throws error if suit is in invalid
            switch (suit) {
                case Suit::CLubs:
                case Suit::Diamonds:
                case Suit::Hearts:
                case Suit::Spades:
                this->suit = suit;
                default: throw std::runtime_error("Invalid parameter suit");
            }

            // Type check for value and throws error if value is invalid
            switch (value) {
                case Value::Ace:
                case Value::One:
                case Value::Two:
                case Value::Three:
                case Value::Four:
                case Value::Five:
                case Value::Six:
                case Value::Seven:
                case Value::Eight:
                case Value::Nine:
                case Value::Ten:
                case Value::Jack:
                case Value::Queen:
                case Value::King:
                this->value = value;
                break;
                default: throw std::runtime_error("Invalid paraneter Value");
            }
        }

        PlayingCard::Suit PlayingCard::get_suit() { return suit; }

        PlayingCard::Value PlayingCard::get_value() { return value; }

        void PlayingCard::set_suit(Suit suit) { this->suit = suit; }

        void PlayingCard::set_value(Value value) {this->value = value; }

        PlayingCard::Suit PlayingCard::int_to_suit(int suit) {
            switch (suit) {
                case 0: return Suit::CLubs; break;
                case 1: return Suit::Diamonds; break;
                case 2: return Suit::Hearts; break;
                case 3: return Suit::Spades; break;
                default: throw std::runtime_error("Invalid Suit type");
            }
        }

        PlayingCard::Suit PlayingCard::string_to_suit(string suit) {
            if (suit == "Clubs") return Suit::CLubs;
            else if (suit == "Diamonds") return Suit::Diamonds;
            else if (suit == "Hearts") return Suit::Hearts;
            else if (suit == "Spades") return Suit::Spades;
            else throw std::runtime_error("Invalid Suit type");
        }

        PlayingCard::Value PlayingCard::int_to_value(int value) {
            switch (value) {
                case 0: return Value::Ace; break;
                case 1: return Value::One; break;
                case 2: return Value::Two; break;
                case 3: return Value::Three; break;
                case 4: return Value::Four; break;
                case 5: return Value::Five; break;
                case 6: return Value::Six; break;
                case 7: return Value::Seven; break;
                case 8: return Value::Eight; break;
                case 9: return Value::Nine; break;
                case 10: return Value::Ten; break;
                case 11: return Value::Queen; break;
                case 12: return Value::King; break;
                default: throw std::runtime_error("Invalid value type");
            }
        }

        PlayingCard::Value PlayingCard::string_to_value(string value) {
            if (value == "Ace") return Value::Ace;
            else if (value == "One") return Value::One;
            else if (value == "Two") return Value::Two;
            else if (value == "Three") return Value::Three;
            else if (value == "Four") return Value::Four;
            else if (value == "Five") return Value::Five;
            else if (value == "Six") return Value::Six;
            else if (value == "Seven") return Value::Seven;
            else if (value == "Eight") return Value::Eight;
            else if (value == "Nine") return Value::Nine;
            else if (value == "Ten") return Value::Ten;
            else if (value == "Queen") return Value::Queen;
            else if (value == "King") return Value::King;
            else throw std::runtime_error("Invalid value type");
        }
    }
}
