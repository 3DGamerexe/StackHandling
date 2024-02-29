/* Homework #3, Aaliyah Madison*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class IntSLLNode {

public:
    class Stack;

    IntSLLNode() {
        next = 0;
    }
    IntSLLNode(string i, IntSLLNode* in = nullptr) {
        info = i;
        next = in;
    }
    string info;
    IntSLLNode* next;
};

class IntSLLNode::Stack {

};

void Menu() {
    std::cout << endl;
    std::cout << std::setw(25) << "M E N U" << endl;
    std::cout << "Binary (0), Octal (1), Hexadecimal (2)" << endl;
    std::cout << "Exit Program(3)" << endl << endl;
}

int main()
{
    int menuValue;
    IntSLLNode::Stack stack;

    do {
        Menu();
        std::cin >> menuValue;

        if (menuValue > 3 || menuValue < 0) {
            std::cout << "Invalid. Enter a number from the menu provided." << endl;
        }

        else {
            std::cout << "Valid. Thank you" << endl;
        }

        if (menuValue == 3) {
            std::cout << "Thank you. Have a nice day!" << endl;
        }
    } while (menuValue != 3);

}
