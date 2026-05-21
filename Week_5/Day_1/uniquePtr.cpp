#include<iostream>
#include<memory>
using namespace std;

void f1()
{
    unique_ptr<int> p1(new int(10));
    unique_ptr<int> p2;
    cout << *p1;
    p2=move(p1);
    // cout << endl << *p1;
    cout << *p2;
}

int main(){
    f1();
    cout << endl;
    return 0;
}

