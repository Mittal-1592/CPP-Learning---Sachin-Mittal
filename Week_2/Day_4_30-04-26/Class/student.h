#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student{
    string m_name;
    int m_age;
    public:
        Student(string name, int age);
        void print();


};

#endif