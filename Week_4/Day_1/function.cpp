#include<iostream>

void fun3(){
    int fun3Variable = 25;
    std::cout<< fun3Variable << std::endl;
}

void fun2(){
    int fun2Variable = 25;
    std::cout<< fun2Variable << std::endl;
}

void fun1(){
    int fun1Variable = 25;
    std::cout<< fun1Variable << std::endl;
}

int main(){
    int mainVariable = 10;
    std::cout << mainVariable;
    fun1();
    return 0;
}