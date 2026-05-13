#include<iostream>
#include "car.h"
using namespace std;

Car :: Car(string name, float power) : car_name(name),E(power){
    cout << " Car constructor is called " << endl;
}

void Car :: print(){
    cout << "The given car is :" << car_name << " the power of engine is : " << E.getPower() << endl;
}