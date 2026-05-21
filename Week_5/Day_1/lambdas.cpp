#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


// By lambda
int main(){
    vector<int> v1={10,13,15,21,23,29,31,35,40};
    for_each(v1.begin(),v1.end(),[](int &x){
        int i;
        for(i=2;i<x;i++){
            if(x%i == 0)
                break;
        }
        if(i==x)
            cout <<x << " ";         
    });
    return 0;
}


// #############################################################################################################
//second method by functors

// class Prime{
//     public:
//         bool isPrime(int x){
//             for(int i=2;i<x;i++)
//                 if(x%i == 0)
//                     return false;
//             return true;
//         }

//         void operator()(int n){
//             if(isPrime(n))
//                 cout << n << " ";
//         }
// };

// int main(){
//     vector<int> v1={10,13,15,21,23,29,31,35,40};
//     Prime p;
//     for_each(v1.begin(),v1.end(),p);
//     return 0;
// }


// #############################################################################################################
// First Methood by making functions

// bool isPrime(int x){
//     for(int i=2;i<x;i++)
//         if(x%i == 0)
//             return false;
//     return true;
// }

// void printPrime(int n){
//     if(isPrime(n))
//         cout << n << " ";
// }


// int main(){
//     vector<int> v1={10,13,15,21,23,29,31,35,40};
//     for_each(v1.begin(),v1.end(),&printPrime);
//     return 0;
// }
