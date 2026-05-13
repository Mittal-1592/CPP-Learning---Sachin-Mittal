#include<iostream>
#include "engine.h"
using namespace std;

Engine :: Engine(float power) : m_power(power){
    cout << "Engine constructor is called " << endl;
}

float Engine :: getPower(){
    return m_power;
}