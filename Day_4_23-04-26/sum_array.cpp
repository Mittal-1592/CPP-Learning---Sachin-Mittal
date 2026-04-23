#include<iostream>
using namespace std;

int getsum(int* arr, int size){
    int sum =0;

    for(int i=0;i<size;i++){
        sum += arr[i];
    }

    return sum;
}

int main(){
    int size;
    cin >> size;
    cout << endl;
    int *arr = new int[size];

    for(int i=0;i<size;i++){
        cin >> arr[i];
    }

    cout << endl;

    cout << " the sum of array is : " << getsum(arr,size);
    return 0;
}