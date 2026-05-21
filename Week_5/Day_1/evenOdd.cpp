#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> v1={1,2,3,4,6,5};
    for_each(v1.begin(),v1.end(),[](int x){
        if(x%2)
            cout<< x << " is odd" << " ";
        else
            cout << x << " is even" << " ";

        cout<< endl;
    });

    return 0;

}