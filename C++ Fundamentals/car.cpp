#include "car.hpp"

//Car Constructor
Car::Car(string _color, string _model, int _power, int dc) {
    color = _color; 
    model = _model; 
    power = _power; 
    pDoorCount = new int(dc);  // *pDoorCount = dc;
}

//Car Destructor
Car::~Car() {
    delete pDoorCount; 
}

void Car::information()
{
    cout << "Model: " << Car::model << endl;           
    cout << "Color: " << Car::color << endl; 
    cout << "Power: " << Car::power << endl; 
    cout << "Door Count: " << *(Car::pDoorCount) << endl; 
}

void Car::setCarColor(string _color)
{
    color = _color; 
}

string Car::getCarColor()
{
    return color; 
}