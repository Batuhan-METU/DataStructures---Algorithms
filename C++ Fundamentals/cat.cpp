#include "cat.hpp"

int Cat::catCount = 0; 
// Constructor 
Cat::Cat(string name) : Animal(name) {
    catCount++; 
}
//Destructor 
Cat::~Cat() {
    catCount--; 
}

void Cat::CatchMouse() {
    cout << Animal::getName() << " catching a mouse!!" << endl; 
}