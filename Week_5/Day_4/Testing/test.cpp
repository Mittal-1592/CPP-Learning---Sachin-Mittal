#include<gtest/gtest.h>

class Atm{
    double _balance;
    public:
        Atm(double balance){
            _balance = balance;
        }

        void withdraw(double amount){
            if(amount > _balance){
                std::cout << "Amount can't withdraw" << std::endl ;
                return;
            }
            _balance -= amount;
        }

        double getBalance(){
            return _balance;
        }
};  

TEST(ATMtest, WhenBalance){
    Atm atm(1000);

    atm.withdraw(300);
    EXPECT_EQ(atm.getBalance(),700);
}