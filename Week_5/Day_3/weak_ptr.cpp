#include <iostream>
#include <memory>
using namespace std;

int main() {

    shared_ptr<int> sp = make_shared<int>(500);

    weak_ptr<int> wp = sp;

    cout << wp.use_count() << endl;

    if(auto temp = wp.lock())
    {
        cout << *temp << endl;
    }
}