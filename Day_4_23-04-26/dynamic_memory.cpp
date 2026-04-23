#include<iostream>
using namespace std;

int main(){
    // int *ptr = new int(10);
    // *ptr = 200;
    // cout << *ptr;

    // cout << sizeof(ptr);

    // int *ptr[9];
    // cout << ptr[0];
    // cout<<endl;
    // cout<<ptr[1];
    // cout<<endl;
    // cout<<ptr[2];
    // cout << *ptr[0];

    int * arr = new int[5];
    for(int i = 0; i<5; i++){
        cin >> arr[i];
    }

    cout << endl;
    for(int i=0;i<5;i++){
        cout << arr[i] << endl;
    }
    return 0;
}