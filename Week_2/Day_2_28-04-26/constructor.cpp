#include<iostream>
using namespace std;

class Example{
    public:
        int data_x;
        int data_y;

        Example(int x , int y){
            data_x = x;
            data_y = y;
        }

        void print(){
            cout << "The value of x is: " << data_x << endl << "The value of y is: " << data_y << endl;
        }
};

int main(){
    Example ex(2,3);
    ex.print();
    return 0;
}