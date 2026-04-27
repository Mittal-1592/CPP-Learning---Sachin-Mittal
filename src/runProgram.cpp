#include <iostream>
#include "validations.h"
#include "matrix.h"
#include "matrixAddition.h"
#include "matrixMultiplication.h"
using namespace std;

void runProgram(){
    while(true){
        int row1, col1, row2, col2;
        cout << "Enter rows and columns for matrix1" << endl;

        cout << "Enter rows : " ;
        row1 = validatePositiveInteger();
        cout << "Enter columns : ";
        col1 = validatePositiveInteger();

        cout << endl << "Enter rows and columns for matrix2" << endl;

        cout << "Enter rows : ";
        row2 = validatePositiveInteger();
        cout << "Enter columns : ";
        col2 = validatePositiveInteger();

        int **matrix1 = createMatrix(row1,col1);
        int **matrix2 = createMatrix(row2,col2);

        int operation = selectOperation();

        if (operation == 1){
            if(!validMatrixAddition(row1,col1,row2,col2)){
                deleteMatrix(matrix1,row1);
                deleteMatrix(matrix2,row2);
                continue;
            }

            cout << endl << "Enter elements of first matrix" << endl;
            insertElements(matrix1,row1,col1);

            cout << endl << "Enter elements of second matrix" << endl;
            insertElements(matrix2,row2,col2);

            int **sum = createMatrix(row1,col1);
            matrixAddition(matrix1,matrix2,sum,row1,col1,row2,col2);

            displayMatrix(row1, col1, sum);
            deleteMatrix(sum,row1);       
        } 
        else{
            if(!validMatrixMultiplication(row1, col1, row2, col2)){
                    deleteMatrix(matrix1,row1);
                    deleteMatrix(matrix2,row2);
                    continue;
                }
                cout << endl << "Enter elements of first matrix" << endl;
                insertElements(matrix1,row1,col1);

                cout << endl << "Enter elements of second matrix" << endl;
                insertElements(matrix2,row2,col2);

                int **multiplication = createMatrix(row1,col2);
                matrixMultiplication(matrix1, matrix2, multiplication, row1, col1,row2,col2);

                displayMatrix(row1, col2, multiplication);
                deleteMatrix(multiplication,row1);     
            }    
        
    deleteMatrix(matrix1,row1);
    deleteMatrix(matrix2,row2);
    
    }
}
        