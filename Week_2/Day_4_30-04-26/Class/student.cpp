#include "student.h"
#include<iostream>
#include <string>
using namespace std;

Student::Student(string name,int age){
    m_name = name;
    m_age = age;
}

void Student :: print(){
    cout << "The name of person is: " << m_name << endl << "Age of person is: " << m_age;
}