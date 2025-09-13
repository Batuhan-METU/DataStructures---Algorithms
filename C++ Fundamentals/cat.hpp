#pragma once 
#include "animal.hpp"

class Cat : public Animal {
    public: 
        Cat(string name); 
        ~Cat(); 
        void CatchMouse(); 
        static int getCatCount(){
            return catCount; 
        }
    private: 
        static int catCount; 
};