#pragma once
#include <iostream>
#include <string> 
using namespace std; 

class Car {
    public: 
        // Constructor
        Car(string _color, string _model, int _power,int dc);  
        
        // Destructor
        ~Car(); 

        void information(); 
        void setCarColor(string _color);
        string getCarColor();

        int *pDoorCount; 

    private: 
        string color, model; 
        int power; 
};