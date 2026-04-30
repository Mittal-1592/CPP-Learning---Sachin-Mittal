#include <iostream>
using namespace std;

class Room
{
public:
    Room()
    {
        cout << "Room created\n";
    }

    ~Room()
    {
        cout << "Room destroyed\n";
    }
};

class House
{
public:
    Room room;   // Composition happening here

    House()
    {
        cout << "House created\n";
    }

    ~House()
    {
        cout << "House destroyed\n";
    }
};

int main()
{
    House h1;
}