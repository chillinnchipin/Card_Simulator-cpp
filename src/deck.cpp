#include <string>
#include <vector>
#include <array>
#include <stdexcept>

#include "../headers/deck.hpp"

namespace cardsim {
    namespace objects {
        Deck::Deck(): deck({}), deck_size(0) {}

        Deck::Deck(Card deck[], size_t size): deck_size(size) {
            for (int i = 0; i < size; i++) this->deck.push_back(deck[i]);
        }

        Deck::Deck(std::vector<Card> deck): deck(deck), deck_size(deck.size()) {}

        size_t Deck::get_deck(Card deck[], size_t *size) {
            for (int i = 0; i < deck_size; i++) deck[i] = this->deck.at(i);
            *size = deck_size;
            return deck_size;
        }

        std::vector<Card> Deck::get_deck() { return deck; }

        Card Deck::get_card(size_t index) {
            if (index > deck_size) throw std::runtime_error("Index out of bound");
            return deck.at(index);
        }

        Card Deck::get_card(string suit, int value) {
            for (Card& card: deck)
                if (card.get_suit() == suit && card.get_value() == value) 
                    return card;
            throw std::runtime_error("Card not found"); 
        }

        size_t Deck::get_cards(Card deck[], size_t *size, Card match) {
            size_t current_size = 0;
            for (Card& card: this->deck) {
                if (card == match) {
                    deck[current_size];
                    current_size++;
                }
            }
            *size = current_size;
            return current_size;
            // TODO remove variable current_size
        }

        std::vector<Card> Deck::get_cards(Card match) {
            std::vector<Card> to_return;
            for (Card& card : deck)
                if (card == match) to_return.push_back(card);
            return to_return;
        }

        size_t Deck::get_cards(Card deck[], size_t *size, string suit, int value) {
            size_t current_size = 0;
            for (Card& card: this->deck) {
                if (card.get_suit() == suit && card.get_value() == value) {
                    deck[current_size] = card;
                    current_size++;
                }
            }
            *size = current_size;
            return current_size;
        }

        std::vector<Card> Deck::get_cards(string suit, int value) {
            std::vector<Card> to_return;
            for (Card& card: deck)
                if (card.get_suit() == suit && card.get_value() == value)
                    to_return.push_back(card);
            return to_return;
        }

        void Deck::set_deck(Deck deck) {
            this->deck = deck.get_deck();
            this->deck_size = this->deck.size();
        }

        void Deck::set_deck(Card deck[], size_t size) {
            for (int i = 0; i < deck_size; i++) {
                this->deck[i] = deck[i];
            }
            this->deck_size = size;
        }

        void Deck::set_deck(std::vector<Card> deck) {
            this->deck = deck;
            this->deck_size = deck.size();
        }

        void Deck::add_card(Card card, int index) { deck.insert(deck.begin() + index, card); }

        void Deck::add_card(string suit, int value, size_t index) { deck.insert(deck.begin() + index, Card(suit, value)); }

        void Deck::append_card(Card card) { deck.push_back(card); }
        
        void Deck::append_card(string suit, int value) { deck.push_back(Card(suit, value)); }
        
        void Deck::prepend_card(Card card) { deck.insert(deck.begin(), card); }
        
        void Deck::prepend_card(string suit, int value) { deck.insert(deck.begin(), Card(suit, value)); }

        Card Deck::remove_card(size_t index) {
            Card to_return = deck.at(index);
            deck.erase(deck.begin() + index);
            return to_return;
        }

        Card Deck::pop_card() {
            Card to_return = deck.back();
            deck.pop_back();
            return to_return;
        }

        Card Deck::pop_head() {
            Card to_return = deck.front();
            deck.erase(deck.begin());
            return to_return;
        }

        Card Deck::peak_card() { return deck.back(); }

        Card Deck::peak_head() { return deck.front(); }
    }
}
