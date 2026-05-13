#ifndef ENGINE_H
#define ENGINE_H

#include<iostream>
using namespace std;

class Engine{
    private:
        float m_power;
    public:
        Engine(float m_power);

        float getPower();


};

#endif