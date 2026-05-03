#include <iostream>
#include "runProgram.h"
#include "matrixAddition.h"
#include "matrix.h"
using namespace std;

bool isValidInteger(string &input){
    if (input.empty())
        return false;

    int start = 0;

    if (input[0] == '-'){
        if (input.length() == 1)
            return false;
        start = 1;
    }

    for (int i = start; i < input.length(); i++){
        if (!isdigit(input[i]))
            return false;
    }

    return true;
}

int validateInteger(){
    string input;

    while (true)
    {
        cin >> input;

        if (isValidInteger(input))
        {
            return stoi(input);
        }

        cout << "Invalid input! Enter integer only: ";
    }
}


int validatePositiveInteger(){
    int number;

    while (true)
    {
        number = validateInteger();

        if (number > 0)
            return number;

        cout << "Invalid Input! Enter positive integer: ";
    }
}

bool validMatrixAddition(int row1, int col1, int row2, int col2){
    if (row1 != row2 || col1 != col2){
        cout << endl << "Operation can not be performed ! Try again !! " << endl << endl;
        return false;
       
    }
    return true;
}

bool validMatrixMultiplication(int row1, int col1, int row2, int col2){
    if(col1 != row2){
        cout << endl << "Operation can not be performed ! Try again !! " << endl << endl;
        return false;
    }

    return true;
}