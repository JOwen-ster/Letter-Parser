#include "LetterParser.hpp"
#include <string>
using std::string;


LetterParse::LetterParse(const string &input) {
    this->input_ = input;
    this->index_ = 0;
    this->current_character_ = input_[index_];
}

string LetterParse::get_input() const {
    return this->input_;
}

void LetterParse::set_input(const string &newInput) {
    this->input_ = newInput;
}

bool LetterParse::parse() { // Grammar
    return stateS() && this->index_ == (get_input().length() - 1) && this->current_character_ == '$';
}

void LetterParse::next_index() {
    this->index_++;
    this->current_character_ = input_[index_];
}

bool LetterParse::stateS() { // State S (Start)
    if (this->current_character_ == 'a') {
        next_index();
        return stateS();
    } else if (this->current_character_ == 'b') {
        next_index();
        return stateB();
    } else if (this->current_character_ == 'c') {
        next_index();
        return stateC();
    }
    return false; // Not in grammar
}

bool LetterParse::stateB() { // State B
    if (this->current_character_ == 'b') {
        next_index();
        return stateB();
    } else if (this->current_character_ == 'a') {
        next_index();
        return stateC();
    }
    return true; // Lambda
}

bool LetterParse::stateC() { // State C
    if (this->current_character_ == 'a') {
        next_index();
        return stateS();
    }
    return true; // Lambda
}

