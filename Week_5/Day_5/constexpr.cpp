#include<iostream>
using namespace std;

constexpr int add(int a,int b){
    return a+b;
}

static_assert(add(1,2) == 3);

int main(){
    int a,b;
    cin >> a>>b;
    cout << add(1,b);
}

// const int size = someRuntimeValue();

// int arr[size]; // may fail

// constexpr int MAX_SIZE = 100;