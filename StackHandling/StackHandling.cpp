/* Homework #3, Aaliyah Madison*/

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using namespace std;

class Node {

public:
    class Stack;
    class LinkedList;

    Node() {
        next = 0;
    }
    Node(string i, Node* in = nullptr) {
        info = i;
        next = in;
    }
    string info;
    Node* next;
};

class Node::LinkedList {
public:
    Node* top = nullptr;
    Node* tmp = nullptr;

    //pushes to the top of the stack
    void push(string value) {
        Node* tmp = new Node(value);
        tmp->next = top;
        top = tmp;
    }

    //removes from the top of the stack
    void pop() {
        while (tmp->next != top) {
            tmp = tmp->next;
        }
        delete top;
        top = tmp;
        top->next = nullptr;
    }

    //prints the Stack
    void print() {
        //Node* current = top;
        while (top != nullptr) {
            std::cout << top->info << " ";
            top = top->next;
        }
    }

};

class Node::Stack {
public:
    int current = 0;
    int intValue = 0;
    Node::LinkedList stack;

    void binary(string value) {
        intValue = stoi(value);
        int i = 0;

        // MARK: CHANGE 
        while (intValue > 0) {
            stack.push(to_string(intValue % 2));
            intValue = intValue / 2;
            i++;
        }
        
        if (value == "0") {
            stack.push(value);
        }
        stack.print();
    }

    void octal(string value) {
        int i = 0;
        intValue = stoi(value);

        while (intValue > 0) {
            stack.push(to_string(intValue % 8));
            intValue = intValue / 8;
            i++;
        }

        if (value == "0") {
            stack.push(value);
        }
        stack.print();
    }

    void hexaDecimal(string value) {
        intValue = stoi(value);
        std::map <int, string> hex = {
            {0, "0"}, {1, "1"}, {2, "2"}, {3, "3"}, {4, "4"},
            {5, "5"}, {6, "6"}, {7, "7"}, {8, "8"}, {9, "9"},
            {10, "A"}, {11, "B"}, {12, "C"}, {13, "D"},
            {14, "E"}, {15, "F"}
        };

        int remainder = intValue % 16;
        if (remainder < 16) {
            stack.push(hex.at(remainder));
        }

        while (intValue > 15) {          
            stack.push(to_string(intValue / 16));    
            intValue = intValue / 16;
        }    
        
        stack.print();
    }
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
    string userValue;
    Node::Stack stack;

    do {
        Menu();
        std::cout << std::setw(20) << "Choose? "; 
        std::cin >> menuValue;

        if (menuValue > 3 || menuValue < 0 || cin.fail()) {
            std::cout << endl;
            std::cout << "Invalid. Enter a number from the menu provided." << endl;
        }

        else {
            
            switch (menuValue) {
            case 0:
                std::cin >> userValue;
                stack.binary(userValue);
                break;
            case 1:
                std::cin >> userValue;
                stack.octal(userValue);
                break;
            case 2:
                std::cin >> userValue;
                stack.hexaDecimal(userValue);
                break;
            }
        }

        if (menuValue == 3) {
            std::cout << "Thank you! Have a nice day!" << endl;
        }
    } while (menuValue != 3);

}
