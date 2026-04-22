#include <iostream>
using namespace std;

int main(){
    // char name = 'a';
    // char* ptr = &name;
    // cout << ptr << endl;

    // char name[34] = "sachin";

    // cout << &name[0];

    int name[7] ={1,2,3,4};
    int* ptr = &name[1];

    cout<< endl;

    char a = 'a';
    char* p = &a;
    cout << *p;
    cout<< endl;
    char b = 'h';
    p = &b;
    cout << (void*)(p);

    return 0;
}