#include <iostream>
#include <string>
#include <stack>
using std::string;


class LetterParse{
    public:
        bool parse()const;
        string get_input()const;
        string get_grammar()const;

        LetterParse(const string &input) : input_(input) {}


    private:
        string input_;
};

