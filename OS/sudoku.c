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