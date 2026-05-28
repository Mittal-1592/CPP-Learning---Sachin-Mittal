#include<iostream>

class A{     
    public:
        int a;

        A(int num){
            a=num;
        }
        void dummy(){
            int a = 4;
            auto p = [this](){
                std::cout << this->a << std::endl;
                 };

            p();
        }
};

int main(){
    A a1(3);
    a1.dummy();
    return 0;
}






int x=6;
const int y=x;
constexpr int z=x;