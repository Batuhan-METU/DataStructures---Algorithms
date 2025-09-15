#include <iostream>

using namespace std; 

class Node {
    public: 
        int value; 
        Node *next; 

        Node(int value) {
            this->value = value; 
            next = nullptr; 
        }
}; 

class Stack {
    private: 
        Node *top; 
        int count; 

    public: 
        Stack() {
            top = nullptr; 
            count = 0; 
        }
        Stack(int value) {
            Node *node = new Node(value); 
            top = node; 
            count = 1; 
        }

        ~Stack() {
            Node *temp = top; 
            while(temp != nullptr) {
                top = top->next; 
                delete temp; 
                temp = top; 
            }
        }

        void printAll() {
            Node *temp = top; 
            while(temp != nullptr) {
                cout << temp->value << ", "; 
                temp = temp->next; 
            }
            cout << endl; 
        }

        void printTop() {
            if (top == nullptr) {
                cout << "There is no top value!!" << endl; 
            }
            cout << "Top value: " << top->value << endl; 
        }

        int getCount() {
            return count; 
        }

        void pushNode(int value) {
            Node *node = new Node(value); 
            node->next = top; 
            top = node; 
            count++; 
        }

        int popNode() {
            if (top == nullptr) {
                exit(1); 
            }
            Node *node = top; 
            int value = node->value; 
            top = top->next; 
            delete node; 
            count--; 
            return value; 
        }

        int isEmpty() {
            if (top == nullptr) {
                return 1; 
            }
            return 0; 
        }
}; 
