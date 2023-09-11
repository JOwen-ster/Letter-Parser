#include <iostream>
#include <string>
#include <stack>
using std::string;


class LetterParse{
    public:
        LetterParse(const string &input);
        
        bool parse();
        string get_input() const;
        void set_input(const string &newInput);


    private:
        string input_;
        size_t index_;
        char current_character_;
        void next_index();
        bool stateS();
        bool stateB();        
        bool stateC();
};

