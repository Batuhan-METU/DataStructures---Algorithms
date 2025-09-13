#include <iostream>

using namespace std; 

class Node {
    public: 
        int value; 
        Node *next, *prev; 

        Node(int value){
            this->value = value; 
            next = nullptr; 
            prev = nullptr; 
        }
};

class DoublyLinkedList {
    private: 
        Node *head; 
        Node *tail; 
        int count; 
    
    public: 
        DoublyLinkedList() {
            head= NULL;  
            tail = NULL; 
            count = 0; 
        }

        DoublyLinkedList(int value) {
            Node *node = new Node(value); 
            head = node; 
            tail = node; 
            count = 1; 
        }

        ~DoublyLinkedList() {
            Node *tmp = head; 
            while(head != nullptr){
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


        void printList() {
            Node* tmp = head; 
            while(tmp != nullptr) {
                cout << tmp->value << " , "; 
                tmp = tmp->next; 
            }

            cout << endl; 
        }   


        void appendNode(int value) {
            Node* node = new Node(value); 
            if (head == nullptr) {
                head = node; 
                tail = node;  
            }
            tail->next = node; 
            node->prev = tail; 
            tail = node;

            count++; 
        }


        void deleteLastNode() {
            if (count == 0) {
                return; 
            }
            Node *node = tail; 
            if (count == 1) {
                head = nullptr; 
                tail = nullptr; 
            }
            else {
            tail = node->prev; 
            tail->next = nullptr; 
            }
            delete node; 
        }


        void addFirst(int value) {
            Node *node = new Node(value); 
            if (count == 0) {
                head = node; 
                tail = node; 
            }
            node->next = head; 
            head->prev = node; 
            head = node; 
            count++; 
        }


        void deleteFirst() {
            if (count == 0) {
                return; 
            }
            Node *temp = head; 
            if (count == 1) {
                head = nullptr; 
                tail = nullptr; 
            }
            head = head->next; 
            head->prev = nullptr; 

            delete temp; 
            count--; 
        }


        Node* getNode(int index) {
            if (index < 0 || index >=count) {
                return nullptr; 
            }
            Node *temp = head; 
            if (index < count /2) {
                for (int i = 0; i<index; i++) {
                    temp = temp->next; 
                }
            }
            else {
                temp = tail; 
                for (int i = count-1; i>index; i--) {
                    temp = tail->prev; 
                }
            }

            return temp; 
        }


        void setNode(int index, int value) {
            Node *temp = getNode(index); 

            if (temp != nullptr) {
                temp->value = value; 
            }
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
                appendNode(value);
                return;  
            }
            Node *node = new Node(value); 
            Node *leftNode = getNode(index-1);
            Node *rightNode = getNode(index); 

            node->next = rightNode; 
            node->prev = leftNode; 
            leftNode->next = node; 
            rightNode->prev = node; 
            count++; 
        }


        void deleteNode(int index) {
            if (index == 0) {
                deleteFirst(); 
                return; 
            }
            else if (index == count - 1) {
                deleteLastNode(); 
                return; 
            }
            Node *temp1 = getNode(index-1), *temp2 = getNode(index);
            temp1->next = temp2->next; 
            temp2->next->prev = temp1; 
            delete temp2; 
            count--; 
        }
}; 


