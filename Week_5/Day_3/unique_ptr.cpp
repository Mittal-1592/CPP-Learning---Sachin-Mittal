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
    

    unique_ptr<MyClass> ptr1 = std::move(ptr2);


    int a = 4;
    // a = lvalue hai 
    // 4 ek literal hai 

    int &x = a;
    // lvalue reference x

    int &&y = 10;
    // rvalue reference

    move(unique_ptr<MyClass &&ptr> )
    [=,&]()->void{

    }


    class A{
        int a;
        public:
         int dummy(){
            [](int a)->
         }
    }

    return 0;
}