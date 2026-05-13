#ifndef CAR_H
#define CAR_H

#include<iostream>
using namespace std;
#include "engine.h"

class Car{
    private:
        string car_name;
    public:
        Engine E;
        Car(string name, float power);

        void print();
};

#endif