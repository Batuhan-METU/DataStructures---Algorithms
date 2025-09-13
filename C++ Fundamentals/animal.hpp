#pragma once 
#include <iostream> 

using namespace std; 

class Animal {
    public: 
        Animal(string _name); 
        void sleep(); 
        void eat(); 
        void setName(string _name); 
        string getName(); 

    private: 
        string name; 
};