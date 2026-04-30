#include<iostream>
using namespace std;

class Ball{
    private:
        string m_color;
        float m_radius;

    public:
        Ball(string color, float radius) : m_color(color), m_radius(radius){

        } 

        void printColour(){
            cout << "Ball(" << m_color << "," << m_radius << endl;
        }

};

int main(){
    Ball blue("blue",10.0);
    blue.printColour();
    
    Ball red("red",12.0);
    red.printColour();

    return 0;
}