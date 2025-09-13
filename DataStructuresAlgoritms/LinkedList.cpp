#include <iostream>

using namespace std; 

class Node {
    public: 
        int value; 
        Node *next; 

        Node(int value){
            this->value = value; 
            next = NULL; 
        }
};

class LinkedList {
    private: 
        Node *head, *tail; 
        int count; 
        
    public: 
        LinkedList() {
            head= NULL;  
            tail = NULL; 
            count = 0; 
        }
        LinkedList(int value){
            Node *node = new Node(value); 
            head = node; 
            tail = node; 
            count = 1; 
        }

        ~LinkedList() {
            Node *tmp = head; 
            while(head){
                head = head->next; 
                delete tmp; 
                tmp = head; 
            }
        }
        

        void printHead() {
            if (head != nullptr) {
                cout << "Head: " << head->value << endl; 
            }
        }


        void printTail() {
            if (tail != nullptr) {
                cout << "Tail: " << tail->value << endl; 
            }
        }


        void getCount() {
            cout << count << endl; 
        }


        void appendList(int value) {
            Node *node = new Node(value); 

            if (count == 0) {
                head = node; 
                tail = node; 
            }
            tail->next = node; 
            tail = node; 
            count++; 
        }


        void printList() {
            Node* tmp = head; 
            while(tmp != nullptr) {
                cout << tmp->value << " , "; 
                tmp = tmp->next; 
            }

            cout << endl; 
        }


        void deleteLastNode() {
            if (count == 0) {
                return; 
            }

            Node* temp1 = head; 
            Node* temp2 = nullptr;
            
            while(temp1->next != nullptr)
            {
                temp2 = temp1; 
                temp1 = temp1->next; 
            }

            tail = temp2; 
            tail->next = nullptr; 
            count--; 
            if (count == 0) {
                head = nullptr; 
                tail = nullptr; 
            }
            delete temp1; 
        }


        void addFirst(int value) {
            Node* newNode = new Node(value); 
            if (count == 0) {
                head = newNode; 
                tail = newNode; 
            }
            newNode->next = head; 
            head = newNode;
            
            count++; 
        }


        void deleteFirst() {
            if (count == 0) {
                return; 
            }
            Node* temp = head; 
            head = head->next;
            count--; 
            if (count == 0) {
                head = nullptr; 
                tail = nullptr; 
            } 
            delete temp; 
        }


        Node* getNode(int index) {
            if (index < 0 || index >=count) {
                return nullptr; 
            }
            Node* temp = head; 
            for (int i = 0; i<index; i++) {
                temp = temp->next; 
            }
            return temp; 
        }


        void setValue(int index, int newValue) {
            Node* temp = getNode(index); 

            if (temp != nullptr) {
                temp->value = newValue; 
            }
            return; 
        }

        void insertNode(int index, int value) {
            if (index < 0 || index > count) {
                return; 
            }
            if (index == 0) {
                addFirst(value); 
                return; 
            }
            if (index == count) {
                appendList(value);
                return;  
            }

            Node* newNode = new Node(value); 
            Node* temp = getNode(index-1); 
            newNode->next = temp->next; 
            temp->next = newNode; 

            count++; 
        }

        void deleteNode(int index) {
            if (index < 0 || index >=count) {
                return; 
            }
            if (index == 0) {
                deleteFirst(); 
            }
            if (index == count-1) {
                deleteLastNode(); 
            }
            Node *temp1 = getNode(index-1), *temp2 = getNode(index);
            temp1->next = temp2->next; 
            delete temp2; 
            count--; 
        }
    }; 

