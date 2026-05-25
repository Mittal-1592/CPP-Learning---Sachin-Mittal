#include<iostream>
#include<memory>
using namespace std;

int main(){
    shared_ptr<int> p1(new int(10));
    shared_ptr<int> p2;
    p2 = p1;

    cout << p1.use_count()<<endl;
    cout << p2.use_count() << endl;

    cout << &p1 << endl;
    cout << *p1;
    cout << endl;
    cout <<&p2;
    return 0;
}