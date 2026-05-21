#include <iostream>
using namespace std;

int divide(int a, int b) {
    int result = a / b;
    return result;
}

int main() {
    int x = 10;
    int y = 0;

    int ans = divide(x, y);

    cout << "Answer = " << ans << endl;

    return 0;
}