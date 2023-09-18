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
    std::cout << std::endl;
    std::cout << "Enter ':q' to quit" << std::endl;
            std::cout << std::left << std::setw(15) << "Token"
        << std::setw(15) << "Number"
        << std::setw(15) << "Identifier"
        << std::setw(15) << "Reserved Word";
    while(true){
        parser.isValidToken();
    }
    return 0;
}
































































//end//