#include<iostream>
using namespace std;

constexpr auto add = [](int a, int b){
    return a + b;
};

int main(){
    cout << add(3,4);
    cout<< endl;

    int a,b;

    cin >> a >> b;

    cout << add(a,b);
    return 0;
}