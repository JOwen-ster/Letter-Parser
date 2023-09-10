#include "LetterParser.hpp"
#include <string>
using std::string;


LetterParse::LetterParse(const string &input) {
    this->input_ = input;
    this->index_ = 0;
}

bool LetterParse::parse() { // Grammar
    return stateS() && this->index_ == this->input_.length() - 1 && this->input_[index_] == '$';
}

bool LetterParse::stateS() { // State S (Start)
    if (this->input_[index_] == 'a') {
        index_++;
        return stateS();
    } else if (this->input_[index_] == 'b') {
        index_++;
        return stateB();
    } else if (this->input_[index_] == 'c') {
        index_++;
        return stateC();
    }
    return false; // Not in grammar
}

bool LetterParse::stateB() { // State B
    if (this->input_[index_] == 'b') {
        index_++;
        return stateB();
    } else if (this->input_[index_] == 'a') {
        index_++;
        return stateC();
    }
    return true; // Lambda
}

bool LetterParse::stateC() { // State C
    if (this->input_[index_] == 'a') {
        index_++;
        return stateS();
    }
    return true; // Lambda
}

string LetterParse::get_input() const {
    return "foo";
}

string LetterParse::get_grammar() const {
    return "foo";
}