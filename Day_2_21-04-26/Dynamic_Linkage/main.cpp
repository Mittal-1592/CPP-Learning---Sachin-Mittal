#include <iostream>
#include "math.h"

int main() {

    int sum = add(5, 3);
    int product = multiply(5, 3);

    std::cout << "Sum = " << sum << std::endl;
    std::cout << "Product = " << product << std::endl;

    return 0;
}