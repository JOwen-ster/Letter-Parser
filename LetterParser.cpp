#include "LetterParser.hpp"
#include <string>
using std::string;


LetterParse::LetterParse(const string &input) {
    set_input(input);
}

string LetterParse::get_input() const {
    return this->input_;
}

void LetterParse::set_input(const string &newInput) {
    this->input_ = newInput;
    this->index_ = 0;
    this->current_character_ = input_[index_];
}

bool LetterParse::parse() { // Grammar
    return stateS() && this->index_ == (get_input().length() - 1) && this->current_character_ == '$';
}

void LetterParse::next_index() {
    this->index_++;
    this->current_character_ = input_[index_];
}

bool LetterParse::stateS() { // State S (Start)
    switch(current_character_){
        case 'a':
            next_index();
            return stateS();
        case 'b':
            next_index();
            return stateB();
        case 'c':
            next_index();
            return stateC();
    }
    return false;
}

bool LetterParse::stateB() { // State B
    switch(current_character_){
        case 'b':
            next_index();
            return stateB();
        case 'a':
            next_index();
            return stateC();
    }
    return true;
}

bool LetterParse::stateC() { // State C
    switch(current_character_){
        case 'a':
            next_index();
            return stateS();
    }
    return true;
}

