#include <iostream>
#include <queue>

using namespace std; 

class Node {
    public: 
        int value; 
        Node *left, *right; 
        
        Node(int value) {
            this->value = value; 
            left = nullptr, right = nullptr;
        }
}; 

class BinarySearchTree {
    public: 
        Node *root; 

    BinarySearchTree() {
        root = nullptr; 
    }

    ~BinarySearchTree() {
        deleteAllNodes(root); 
    }

    void deleteAllNodes(Node *node) {
        if (node == nullptr) {return;}

        if (node->left != nullptr) {
            deleteAllNodes(node->left); 
        }
        if (node->right != nullptr) {
            deleteAllNodes(node->right); 
        }
        delete node; 
    }


    bool insertRecursive(Node* &node, int value) {
        if (node == nullptr) {
            node = new Node(value); 
            return true; 
        }
        if (node->value == value) {
            cout << "Same node is already exists!!" << endl;
            return false;  
        }

        if (value < node->value) {
            return insertRecursive(node->left, value); 
        }
        else {
            return insertRecursive(node->right, value); 
        }
        
    }
    bool insertNodeRecursive(int value) {
        return insertRecursive(root, value); 
    }


    bool insertNodeIterative(int value) {
        Node *node = new Node(value); 

        if (root == nullptr) {
            root = node; 
            return true; 
        }

        Node *tmp = root; 
        while(true) {
            if (node->value == tmp->value) {
                cout << "Same node is already exists!!" << endl; 
                delete node; // clear the node that created but not inserted ! 
                return false; 
            }
            if (node->value < tmp->value) {
                if (tmp->left == nullptr) {
                    tmp->left = node; 
                    return true; 
                }
                tmp = tmp->left; 
            }
            else {
                if (tmp->right == nullptr) {
                    tmp->right = node; 
                    return true; 
                }
                tmp = tmp->right; 
            }
        }
    }

    void DFSPreOrderPrintAllNodes(Node *node) {
        cout << node ->value << " , "; 
        if (node->left != nullptr) {
            DFSPreOrderPrintAllNodes(node->left); 
        }
        if (node ->right != nullptr) {
            DFSPreOrderPrintAllNodes(node ->right); 
        }
    }

    Node *DFSPreOrderSearch(Node *node, int searchingValue) {
        if (node == nullptr || node ->value == searchingValue) {
            return node; 
        }

        if (searchingValue < node->value) {
            return DFSPreOrderSearch(node->left, searchingValue); 
        }
        else {
            return DFSPreOrderSearch(node->right, searchingValue); 
        }
    }

    void DFSPostOrderPrintAllNodes(Node *node) {
        if (node->left != nullptr) {
            DFSPostOrderPrintAllNodes(node->left); 
        }
        if (node ->right != nullptr) {
            DFSPostOrderPrintAllNodes(node ->right); 
        }
        cout << node ->value << " , "; 
    }

    void DFSInOrderPrintAllNodes(Node *node) {
        if (node->left != nullptr) {
            DFSInOrderPrintAllNodes(node->left); 
        }
        cout << node ->value << " , ";
        if (node ->right != nullptr) {
            DFSInOrderPrintAllNodes(node ->right); 
        }
    }

    void BreadthFirstPrintAllNodes() {
        queue<Node*> queue1; 
        queue1.push(root); 

        while(queue1.size() > 0) {
            Node *node = queue1.front(); 
            queue1.pop(); 

            cout << node->value << " , "; 
            if(node->left != nullptr) {
                queue1.push(node->left); 
            }
            if (node->right != nullptr) {
                queue1.push(node->right); 
            }
        }
    }
}; 

