#include "LetterParser.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
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

void LetterParse::isValidToken(){
    std::string tok;
    string isNum = "yes"; // t
    string isIdentifier = "yes"; // t
    string isReserved = "no"; // f
    const string reserved[5] = {"while", "for", "switch", "do", "return"};
    std::getline(std::cin, tok);
    if(tok == ":q") exit(0);

    if(tok.empty()){
        return;
    }else{
        for(const char &c : tok){
            if(!isdigit(c)){
                isNum = "no";
                break;
            }
        }

        if(tok[0] == '_' || isalpha(tok[0])){
            for(int i = 1; i < tok.size(); i++){
                if(!isalnum(tok[i]) && tok[i] != '_'){
                    isIdentifier = "no";
                    break;
                }
            }
        }else{
            isIdentifier = "no";
        }

        for(int i = 0; i < reserved->size(); i++){
            if(tok == reserved[i]){
                isReserved = "yes";
                break;
            }
        }
    }

    std::cout << std::left << std::setw(15) << tok
    << std::setw(15) << isNum
    << std::setw(15) << isIdentifier
    << std::setw(15) << isReserved;
};