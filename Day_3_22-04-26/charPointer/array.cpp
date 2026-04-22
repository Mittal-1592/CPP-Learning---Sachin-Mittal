#include<iostream>
using namespace std;

int sum(int* arr){
    int sum = 0;
    for(int i=0; i<4 ;i++){
        sum += arr[i];
    }

    return sum;
}

int main(){
    int arr[5] = {1,2,3,4,5};

    cout << "Sum of array is : " <<  sum(&arr[1]);
    return 0;
}