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
 * (<topRow>,<bottomRow>,<lefColumn>,<rightColumn>)
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

/**(0,8,0,0)**/
    col_1.topRow = 0;
    col_1.bottomRow = 8;
    col_1.leftColumn = 0;
    col_1.rightColumn = 0;

/**(0,8,1,1)**/
    col_2.topRow = 0;
    col_2.bottomRow = 8;
    col_2.leftColumn = 1;
    col_2.rightColumn = 1;

/**(0,8,2,2)**/
    col_3.topRow = 0;
    col_3.bottomRow = 8;
    col_3.leftColumn = 2;
    col_3.rightColumn = 2;

/**(0,8,3,3)**/
    col_4.topRow = 0;
    col_4.bottomRow = 8;
    col_4.leftColumn = 3;
    col_4.rightColumn = 3;

/**(0,8,4,4)**/
    col_5.topRow = 0;
    col_5.bottomRow = 8;
    col_5.leftColumn = 4;
    col_5.rightColumn = 4;

/**(0,8,5,5)**/
    col_6.topRow = 0;
    col_6.bottomRow = 8;
    col_6.leftColumn = 5;
    col_6.rightColumn = 5;

/**(0,8,6,6)**/    
    col_7.topRow = 0;
    col_7.bottomRow = 8;
    col_7.leftColumn = 6;
    col_7.rightColumn = 6;

/**(0,8,7,7)**/
    col_8.topRow = 0;
    col_8.bottomRow = 8;
    col_8.leftColumn = 7;
    col_8.rightColumn = 7;

/**(0,8,8,8)**/
    col_9.topRow = 0;
    col_9.bottomRow = 8;
    col_9.leftColumn = 8;
    col_9.rightColumn = 8;    


    

}