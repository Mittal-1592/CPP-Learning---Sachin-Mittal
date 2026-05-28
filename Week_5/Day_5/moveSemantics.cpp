#include<iostream>
using namespace std;


int main(){
    int x = 10;

    const int& a = x;
    const int& b = 20;

    cout << x << " "<<a << " " << b <<endl;

    x=7;
   cout << x << " "<<a << " " << b <<endl;
    return 0;
}



