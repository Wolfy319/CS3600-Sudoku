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
    struct col_1; 
    struct col_2;
    struct col_3;
    struct col_4;
    struct col_5;
    struct col_6;
    struct col_7;
    struct col_8;
    struct col_9;

/** Row struct initialization **/
    struct row_1;
    struct row_2;
    struct row_3;
    struct row_4;
    struct row_5;
    struct row_6;
    struct row_7;
    struct row_8;
    struct row_9;

/** Sub_Grid struct intialization **/
    struct grid_1;
    struct grid_2;
    struct grid_3;
    struct grid_4;
    struct grid_5;
    struct grid_6;
    struct grid_7;
    struct grid_8;
    struct grid_9;
    

    

}