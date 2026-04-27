#include<iostream>
using namespace std;

class Book{
    public:
        string Name;
        string Author;
        Book(string name, string author){
            Name = name;
            Author = author;
            cout << Name + " Constructor Called" << endl;
        }

        ~Book(){
            cout << Name + " Destructor Called" << endl;
        }
    };



int main(){
    Book book1("CPP","Balaguruswamy");
    Book book2("Maths","Pearson");

    return 0;
}