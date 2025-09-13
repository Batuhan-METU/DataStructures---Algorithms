#include "animal.hpp"

Animal::Animal(string _name) {
    Animal::name = _name; 
}

void Animal::eat() {
    cout << Animal::name << " eats" << endl; 
}

void Animal::sleep() {
    cout << Animal::name << " sleeps" << endl; 
}

void Animal::setName(string _name) {
    Animal::name = _name; 
}

string Animal::getName() {
    return Animal::name; 
}