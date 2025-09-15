#include <iostream>

using namespace std; 

class Node {
    public: 
        int value; 
        Node *next; 

        Node (int value) {
            this->value = value; 
            next = nullptr; 
        }
}; 

class Queue {
    private: 
        Node *head, *tail;
        int count;
    public: 
        Queue() {
            head = nullptr, tail = nullptr; 
            count = 0; 
        }  
        Queue(int value) {
            Node *node = new Node(value); 
            head = node;
            tail = node; 
            count = 1; 
        }

        ~Queue() {
            Node *tmp = head; 
            while(head) {
                head = head->next; 
                delete tmp; 
                tmp = head; 
            }
        }

        void printAll() {
            Node *tmp = head; 
            while(tmp) {
                cout << tmp->value << ", "; 
                tmp = tmp->next; 
            }
            cout << endl; 
        }

        int getHeadValue() {
            if (head != nullptr) {
                return head->value; 
            }
            return INT_MIN;
        }

        int getTailValue() {
            if (head != nullptr) {
                return tail->value; 
            }
            return INT_MIN;  
        }

        int getCount() {
            return count; 
        }

        void enqueue(int value) {
            Node *node = new Node(value); 
            if (head == nullptr) {
                head = node; 
                tail = node; 
            }
            tail->next = node; 
            tail = node; 
            count++; 
        }

        int dequeue() {
            if (head == nullptr) {
                cout << "There is no value for dropping!!" << endl;
                exit(1);  
            }
            Node *node = head;
            int value = node->value;  

            if (count == 1) {
                head = nullptr; 
                tail = nullptr;
            }
            else {
                head = head->next; 
            }
            delete node;  
            count--; 
            return value; 
        }

        int isEmpty() {
            if (count == 0) {
                return 1; 
            }
            return 0; 
        }
};


