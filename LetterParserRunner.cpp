#include <iostream>
#include <map>
#include <vector>
#include <string>
using std::string;

class CFGParser {
public:
    CFGParser(const std::string& input) : input(input) {}

    bool parse() {
        currentIndex = 0;
        return parseS() && currentIndex == input.length() - 1 && input[currentIndex] == '$';
    }

private:
    bool parseS() { // State S (Start)
        if (input[currentIndex] == 'a') {
            currentIndex++;
            return parseS();
        } else if (input[currentIndex] == 'b') {
            currentIndex++;
            return parseB();
        } else if (input[currentIndex] == 'c') {
            currentIndex++;
            return parseC();
        }
        return false; // Invalid character
    }

    bool parseB() { // State B
        if (input[currentIndex] == 'b') {
            currentIndex++;
            return parseB();
        } else if (input[currentIndex] == 'a') {
            currentIndex++;
            return parseC();
        }
        return true; // Lambda transition (empty string)
    }

    bool parseC() { // State C
        if (input[currentIndex] == 'a') {
            currentIndex++;
            return parseS();
        }
        return true; // Lambda transition (empty string)
    }

    std::string input;
    size_t currentIndex;
};

int main() {
    string input_;
    char continue_;
    while(true){
        std::cout << "Enter an input string with $ at the end: ";
        std::cin >> input_;
        CFGParser parser(input_);

        if (parser.parse()) {
            std::cout << "Accepted" << std::endl;
        } else {
            std::cout << "Rejected" << std::endl;
        }
        std::cout << "Continue? [y/n] ";
        std::cin >> continue_;
        if(continue_ == 'n') break;
    }
    return 0;
}

