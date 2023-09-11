#include "LetterParser.cpp"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;


int main() {
    string in;
    char continue_;
    while(true){
        cout << "Enter a token with $ at the end: ";
        cin >> in;
        LetterParse parser("");
        parser.set_input(in);
        bool determine = parser.parse();

        if (determine) cout << "Token " << parser.get_input() << " is accepted by the machine."<< endl;
        else cout << "Token " << parser.get_input() << " is rejected by the machine."<< endl;

        cout << "Continue? [y/n] ";
        cin >> continue_;
        if(continue_ == 'n') break;
    }
    return 0;
}

