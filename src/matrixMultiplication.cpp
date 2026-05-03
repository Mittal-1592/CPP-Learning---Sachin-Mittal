#include <iostream>
#include "matrixMultiplication.h"
#include "matrix.h"
using namespace std;


void matrixMultiplication(int **matrix1, int ** matrix2, int** multiplication, int row1, int col1, int row2, int col2){
    for(int i = 0; i < row1; ++i){
        for(int j = 0; j < col2; ++j){
            multiplication[i][j]=0;
            for(int k = 0; k < col1; ++k)
            {
                multiplication[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }           
    }    
    
    cout<< endl << "The Multiplication of Matrix are: " << endl;
}