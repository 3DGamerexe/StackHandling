/* Homework #3, Aaliyah Madison*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Node {

public:
    class Stack;
    class LinkedList;

    Node() {
        next = 0;
    }
    Node(int i, Node* in = nullptr) {
        info = i;
        next = in;
    }
    int info;
    Node* next;
};

class Node::LinkedList {
public:
    Node* top = nullptr;

    //pushes to the top of the stack
    void push(int value) {
        Node* tmp = new Node(value);
        tmp->next = top;
        top = tmp;
    }

    //removes from the top of the stack
    void pop() {
        Node* tmp = nullptr;
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

        if (top == nullptr) {
            std::cout << "Value of 0." << endl;
        }
        std::cout << endl;     
    }
};

class Node::Stack {
public:
    int current;
    Node::LinkedList stack;

    void binary(int value) {
        int i = 0;

        while (value > 0) {
            stack.push(value % 2);
            value = value / 2;
            i++;
        }
        stack.print();
    }

    void octal(int value) {
        int i = 0;
        while (value > 0) {
            stack.push(value % 8);
            value = value / 8;
            i++;
        }
        stack.print();
    }

    void hexaDecimal() {

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
    int userValue;
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
            }
        }

        if (menuValue == 3) {
            std::cout << "Thank you. Have a nice day!" << endl;
        }
    } while (menuValue != 3);

}
