#include<iostream>
#include<memory>
using namespace std;

class MyClass{
    public:
        MyClass(){
            cout << "ctor" << endl;
        }

        ~MyClass(){
            cout <<"dtor" << endl;
        }
};

int main(){
    unique_ptr<MyClass> ptr2  = make_unique<MyClass>();

    {
        cout<<"hello1 "<< endl; 
        unique_ptr<MyClass> ptr(new MyClass());
        cout<<"hello2"<< endl;
    }
    


    

    return 0;
}