#include<assert.h>

int addNumbers(int a, int b){
    return a + b;
}

int subtractNumbers(int a, int b){
    return a - b;
}

void test_add(){
    assert(addNumbers(3,5) == 8);
    assert(addNumbers(13,5) == 18);
    assert(addNumbers(32,108) == 140);
    assert(addNumbers(56,5) == 61);
}

void test_subtract(){
    assert(subtractNumbers(3,5) == -2);
    assert(subtractNumbers(23,5) == 18);
    assert(subtractNumbers(13,1) == 12);
    assert(subtractNumbers(13,5) == 8);
}

int main(){
    test_add();
    test_subtract();
    return 0;
}