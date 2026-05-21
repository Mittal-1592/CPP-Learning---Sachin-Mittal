#include<iostream>
using namespace std;
#include<vector>
#include <gtest/gtest.h>


class Stack{
    vector<int> v = {};
    public:
        void push(int value){
            v.push_back(value);
        }

        int pop(){
            if(v.size()){
                int value = v.back();
                v.pop_back();
                return value;
            }
            return -1;
        }

        int size(){
            return v.size();
        }
};


struct MyStack:public testing::Test{
    Stack s1;
    void SetUp(){
        int arr[] = {1,2,3,4,5,6,7,8,9};
        for (auto element : arr){
            s1.push(element);
        }
    }
    void tear(){

    }
};

TEST_F(MyStack,PopOut){
    int lastPoppedValue = 9;
    while(lastPoppedValue != 1){
        ASSERT_EQ(s1.pop(),lastPoppedValue--);
    }
}