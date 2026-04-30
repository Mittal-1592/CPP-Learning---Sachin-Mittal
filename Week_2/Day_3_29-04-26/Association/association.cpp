#include<iostream>
using namespace std;

class Student{
    public:
        string name;

        Student(string Name){
            name = Name;
            cout << " I am a student" << endl;
        }
};

class Teacher{
    public:
        string name;

        Teacher(Student s){
                        cout << s.name << endl;

            cout << "I am in teacher class " << endl;
        }

        void teach(Student s){
            cout << s.name << endl;
        }
}
;


int main(){
    
    Student s("rahul");
    Teacher t1(s);
    t1.teach(s);
    return 0;
}