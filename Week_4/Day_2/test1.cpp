#include<iostream>
#include<gtest/gtest.h>

using namespace std;

class MyClass{
    string id;
    public:
        MyClass(string _id) : id(_id){

        }
        string getId(){
            return id;
        }

};

// TEST(TestName, SubTest_2){
//     EXPECT_TRUE(1==2);
//     cout << "kya kar rahe ho";
// }


// TEST(TestName, SubTest_1){
//     ASSERT_FALSE(1==2);
//     cout<<"sachin"<< endl;
// }

TEST(TestName, Test_3){

    MyClass mc("root");

    string value = mc.getId();

    ASSERT_EQ(value,"root");
}



// int main(int argc,char **argv){
//     testing::InitGoogleTest(&argc,argv);
//     return RUN_ALL_TESTS();
// }