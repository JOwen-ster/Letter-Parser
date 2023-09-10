#include <iostream>
#include <string>
#include <stack>
using std::string;


class LetterParse{
    public:
        LetterParse(const string &input) {}
        
        bool parse();
        string get_input() const;
        string get_grammar() const;


    private:
        string input_;
        size_t index_;
        bool stateS();
        bool stateB();        
        bool stateC();
};

