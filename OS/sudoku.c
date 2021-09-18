/**
 * A sudoku solution validator
 * Author: Kyle Brown
 * Date: 9/15/21
 * Version 1.0
 * 
 * */

#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>


/** Global structures: all threads share this data **/
int sudokuPuzle[9][9];
int boolCol[9];
int boolRow[9];
int boolSubGrid[9];


/** A structure for rows and columns to be preocessed by index by each thread
 * Indexes are 0 - 8 
 * **/
typedef struct indexPro{
   int topRow;
   int bottomRow;
   int leftColumn;
   int rightColumn;
      
};

void sudokuMatrix(){
    FILE *filePointer;
    filePointer = fopen("sudokuPuzzle.txt", "r");
}

int main(){

/** Column struct intialization **/
    struct indexPro col_1; 
    struct indexPro col_2;
    struct indexPro col_3;
    struct indexPro col_4;
    struct indexPro col_5;
    struct indexPro col_6;
    struct indexPro col_7;
    struct indexPro col_8;
    struct indexPro col_9;

/** Row struct initialization **/
    struct indexPro row_1;
    struct indexPro row_2;
    struct indexPro row_3;
    struct indexPro row_4;
    struct indexPro row_5;
    struct indexPro row_6;
    struct indexPro row_7;
    struct indexPro row_8;
    struct indexPro row_9;

/** Sub_Grid struct intialization **/
    struct indexPro grid_1;
    struct indexPro grid_2;
    struct indexPro grid_3;
    struct indexPro grid_4;
    struct indexPro grid_5;
    struct indexPro grid_6;
    struct indexPro grid_7;
    struct indexPro grid_8;
    struct indexPro grid_9;
    
/************************************************************************************************************************************/

    





    

}