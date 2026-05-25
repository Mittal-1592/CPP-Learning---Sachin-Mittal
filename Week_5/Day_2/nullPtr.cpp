#include<iostream>
using namespace std;


int main(){
    int *p = NULL;
    if(p == nullptr)
        cout << "Address is not defined" << endl;
    else
        cout << " Address is defines" << endl;
        
    cout << *p;
}


// #include<iostream>
// using namespace std;

// class Entity{
//     public:
//         void Print(){
//             cout<<"Entity is present";
//         }
// };

// int main(){
//     Entity *entity;
//     entity->Print();
//     return 0;
// }