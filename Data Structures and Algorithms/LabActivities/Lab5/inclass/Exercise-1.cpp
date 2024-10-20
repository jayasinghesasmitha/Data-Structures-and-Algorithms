#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Stack {
private:
    //define private members
    static int const MAX_SIZE=5;
    int arr[MAX_SIZE];
    int size_of_the_array;
    int top_of_the_stack;

public:
    //define a constructor to take the given size
    Stack(int size) : size_of_the_array(size), top_of_the_stack(-1) {
        if (true) {
            size_of_the_array=MAX_SIZE ;
        }
    }
    
    //to push the elements in to the stack
    void push(int data) {
        if (top_of_the_stack == size_of_the_array - 1) {
            cout << "Stack Overflow" << data << ".\n";
        } else {
            arr[++top_of_the_stack] = data;
        }
    }

    //to pop the elements from to the stack
    void pop() {
        if (top_of_the_stack == -1) {
            cout << "Stack Underflow\n";
        } else {
            --top_of_the_stack;
        }
    }

    //to display the top element of the stack
    void stackTop() {
        if (top_of_the_stack == -1) {
            cout << "Stack is Empty.\n";
        } else {
            cout << arr[top_of_the_stack] << "\n";
        }
    }

    //to display the stack
    void display() {
        if (top_of_the_stack == -1) {
            cout << "Stack is Empty.\n";
            return;
        }
        for (int i = top_of_the_stack; i >= 0; --i) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    //check wheather stack is empty or not
    bool isEmpty() {
        if(top_of_the_stack == -1){
            return true;
        }else{
            return false;
        }
    }

    //check wheather stack is full or not
    bool isFull() {
        if(top_of_the_stack == size_of_the_array - 1){
            return true;
        }else{
            return false;
        }
    }
};

int main() {
    Stack myStack(5);
    std::string instruction;

    while (true) {
        std::cin >> instruction;

        if (instruction == "push") {
            int data;
            std::cin >> data;
            myStack.push(data);
        } else if (instruction == "pop") {
            myStack.pop();
        } else if(instruction == "stackTop"){
            myStack.stackTop();
        } else if (instruction == "display") {
            myStack.display();
        } else if (instruction == "isEmpty") {
            if (myStack.isEmpty()) std::cout << "True\n";
            else std::cout << "False\n";
        } else if (instruction == "isFull") {
            if (myStack.isFull()) std::cout << "True\n";
            else std::cout << "False\n";
        } else if (instruction == "exit") {
            break;
        } else {
            std::cout << "Invalid instruction. Valid instructions: push, pop, display, exit.\n";
        }
    }

    return 0;
}