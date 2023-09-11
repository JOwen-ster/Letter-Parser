#include "LetterParser.cpp"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;


int main() {
    string in;
    char continue_;
    LetterParse parser("");
    while(true){
        cout << "Enter a token with $ at the end: ";
        cin >> in;
        parser.set_input(in);

        if (parser.parse()) cout << "Token " << parser.get_input() << " is accepted by the machine."<< endl;
        else cout << "Token " << parser.get_input() << " is rejected by the machine."<< endl;

        cout << "Continue? [y/n] ";
        cin >> continue_;
        if(continue_ == 'n') break;
    }
    return 0;
}

