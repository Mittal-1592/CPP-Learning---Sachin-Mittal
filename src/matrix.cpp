#include <iostream>
#include "../inc/validations.h"
using namespace std;

int** createMatrix(int rows, int columns){
    int** matrix = new int*[rows];
    for(int i=0; i<rows; i++){
        matrix[i] = new int[columns];
    }

    return matrix;
}

int selectOperation(){
    cout << endl << "Enter the operation you want to perform : " << endl;
    cout << "1. For Addition" << endl;
    cout << "2. For Multiplication" << endl << endl;

    int number;

    while(true){
        number = validateInteger();
        if(cin && (number == 1 || number == 2)){
            return number;
        }
        cout << endl << "Enter valid operation (1 or 2):";
    }
}

void insertElements(int** matrix, int rows, int columns){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            int element = validateInteger();
            matrix[i][j] = element;
        }
    }
}

void deleteMatrix(int** matrix, int rows){
    for(int i=0; i<rows; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr; 
}

void displayMatrix(int row, int col, int** matrix){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}