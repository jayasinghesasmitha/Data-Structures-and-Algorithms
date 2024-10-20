#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top; 
public:
    Stack() : top(nullptr) {}

    //declare a function to display the last added value into the stack
    void push(int data) {
        Node* new_Node = new Node(data);
        new_Node->next = top;
        top = new_Node;
    }

    //declare a function to remove the last added value into the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
        } else {
            Node* head = top;
            top = top->next;
            delete head; 
        }
    }
    
    //declare a function to displaythe remaining stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
        } else {
            Node* tmp = top;
            while (tmp != nullptr) {
                cout<<tmp->data<<" ";
                tmp = tmp->next;
            }
            cout << "\n";
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int stackTop() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }
};

int main() {
    Stack myStack;
    std::string instruction;

    while (true) {
        std::cin >> instruction;

        if (instruction == "push") {
            int data;
            std::cin >> data;
            myStack.push(data);
        } else if (instruction == "pop") {
            myStack.pop();
        } else if (instruction == "display") {
            myStack.display();
        } else if (instruction == "isEmpty") {
            if (myStack.isEmpty()) std::cout << "True\n";
            else std::cout << "False\n";
        } else if (instruction == "stackTop") {
            std::cout << myStack.stackTop() << "\n";
        } else if (instruction == "exit") {
            break;
        } else {
            std::cout << "Invalid instruction. Valid instructions: push, pop, display, exit.\n";
        }
    }

    return 0;
}