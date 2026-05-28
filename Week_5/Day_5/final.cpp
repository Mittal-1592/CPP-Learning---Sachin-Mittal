#include<iostream>
using namespace std;

class A {
    public:
      virtual void print() final{
            cout <<  "Hello";
        }
};

class B: public A{
    public:
        void print(){
            cout << "Buffalo";
        }
};

int main(){
    A *a = new B();
    a->print();
    return 0;
}