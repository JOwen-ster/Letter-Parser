#include "LetterParser.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;


int main() {
    string input;
    char continue_;
    while(true){
        cout << "Enter a string with $ at the end: ";
        cin >> input;
        LetterParse parser(input);

        if (parser.parse()) {
            cout << "Accepted" << endl;
        } else {
            cout << "Rejected" << endl;
        }
        cout << "Continue? [y/n] ";
        cin >> continue_;
        if(continue_ == 'n') break;
    }
    return 0;
}