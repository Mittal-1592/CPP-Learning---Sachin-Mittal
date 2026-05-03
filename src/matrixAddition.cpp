#include "matrixAddition.h"
#include "matrix.h"
#include <iostream>
using namespace std;

void matrixAddition(int **matrix1, int ** matrix2, int** sum, int row1, int col1, int row2, int col2){
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    
    cout<< endl << "The Addition of Matrix are: " << endl;
}