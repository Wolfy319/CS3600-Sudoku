/**
 * A sudoku solution validator
 * Author: Kyle Brown & INSERT NAME
 * Date: 9/15/21
 * Version 1.0
 * 
 * */

#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>


typedef int bool;
    #define TRUE 1;
    #define FALSE 2;



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

/** Reads the sudokuPuzzle.txt into sudokuPuzzle[][] **/
void sudokuMatrix(){
    FILE *filePointer;
    filePointer = fopen("sudokuPuzzle.txt", "r");
    int row;
    int col;
    for(row = 0; row < 9; row++){
        for(col = 0; col < 9; col++){
            fscanf(filePointer,"%d", &sudokuPuzle[row][col]);
        }

    }
    /**printSudokuPuzzle();**/
}

/** Prints the sudoku puzzle from the array in sudoku format **/
void printSudokuPuzzle(){
    printf("The Sudoku Puzzle \n");
    int row;
    int col;
    for(row = 0; row < 9; row++){
        for(col = 0; col < 9; col++){
            printf("%d ", sudokuPuzle[row][col]);
            if(col == 8){
                printf("\n");
            }
        }
        
    }
    
}

/** Compares to integer values for qsort function **/
int compareVals(const void * a, const void * b ){
    return ( *(int*)a - *(int*)b );
}

/** Checks if the given column has all values
 * first sorts array columnValues using std lib qsort
 * */
void colCheck(struct indexPro col_){
    int colValues[9];
    bool contains = TRUE; 
    
    for(int row = 0; row < 9; row++){
        colValues[row] = sudokuPuzle[row][col_.leftColumn]; 
    }

    qsort(colValues, 9, sizeof(int), compareVals);
   
    for(int val = 1; val < 10; val++){
        for(int mover = 0; mover < 9; mover++){
            if(colValues[mover] != val){
                contains = FALSE;
                break; 
            }
        }
    }
    boolCol[col_.leftColumn] = contains;
    printf("bool check: ");
    printf("%d ", boolCol[0]);
     
    
    
}


void rowCheck(struct indexPro row_){
    int rowValues[9];
    bool contains = TRUE;

    for(int col = 0; col < 9; col++){
        rowValues[col] = sudokuPuzle[row_.topRow][col];
        printf("%d ", rowValues[col]);
    }

    for(int u = 0; u < 9; u++){
        printf("%d ", rowValues[u]);
    }

    qsort(rowValues, 9, sizeof(int), compareVals);
    
    
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
/** Set Column indexs **/
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

/************************************************************************************************************************************/

/** Set Row indexs **/
/**(0,0,0,8)**/
    row_1.topRow = 0;
    row_1.bottomRow = 0;
    row_1.leftColumn = 0;
    row_1.rightColumn = 8;

/**(1,1,0,8)**/
    row_2.topRow = 1;
    row_2.bottomRow = 1;
    row_2.leftColumn = 0;
    row_2.rightColumn = 8;

/**(2,2,0,8)**/
    row_3.topRow = 2;
    row_3.bottomRow = 2;
    row_3.leftColumn = 0;
    row_3.rightColumn = 8;

/**(3,3,0,8)**/
    row_4.topRow = 3;
    row_4.bottomRow = 3;
    row_4.leftColumn = 0;
    row_4.rightColumn = 8;

/**(4,4,0,8)**/
    row_5.topRow = 4;
    row_5.bottomRow = 4;
    row_5.leftColumn = 0;
    row_5.rightColumn = 8;

/**(5,5,0,8)**/
    row_6.topRow = 5;
    row_6.bottomRow = 5;
    row_6.leftColumn = 0;
    row_6.rightColumn = 8;

/**(6,6,0,8)**/
    row_7.topRow = 6;
    row_7.bottomRow = 6;
    row_7.leftColumn = 0;
    row_7.rightColumn = 8;

/**(7,7,0,8)**/
    row_8.topRow = 7;
    row_8.bottomRow = 7;
    row_8.leftColumn = 0;
    row_8.rightColumn = 8;

/**(8,8,0,8)**/
    row_9.topRow = 8;
    row_9.bottomRow = 8;
    row_9.leftColumn = 0;
    row_9.rightColumn = 8;    

/************************************************************************************************************************************/

/** Set Sub_Grid indexs **/
/**(0,2,0,2)**/
    grid_1.topRow = 0;
    grid_1.bottomRow = 2;
    grid_1.leftColumn = 0;
    grid_1.rightColumn = 2;

/**(0,2,3,5)**/
    grid_2.topRow = 0;
    grid_2.bottomRow = 2;
    grid_2.leftColumn = 3;
    grid_2.rightColumn = 5;

/**(0,2,6,8)**/
    grid_3.topRow = 0;
    grid_3.bottomRow = 2;
    grid_3.leftColumn = 6;
    grid_3.rightColumn = 8;

/**(3,5,0,2)**/
    grid_4.topRow = 3;
    grid_4.bottomRow = 5;
    grid_4.leftColumn = 0;
    grid_4.rightColumn = 2;

/**(3,5,3,5)**/
    grid_5.topRow = 3;
    grid_5.bottomRow = 5;
    grid_5.leftColumn = 3;
    grid_5.rightColumn = 5;

/**(3,5,6,8)**/
    grid_6.topRow = 3;
    grid_6.bottomRow = 5;
    grid_6.leftColumn = 6;
    grid_6.rightColumn = 8;

/**(6,8,0,2)**/
    grid_7.topRow = 6;
    grid_7.bottomRow = 8;
    grid_7.leftColumn = 0;
    grid_7.rightColumn = 2;

/**(6,8,3,5)**/
    grid_8.topRow = 6;
    grid_8.bottomRow = 8;
    grid_8.leftColumn = 3;
    grid_8.rightColumn = 5;

/**(6,8,6,8)**/
    grid_9.topRow = 6;
    grid_9.bottomRow = 8;
    grid_9.leftColumn = 6;
    grid_9.rightColumn = 8;
    
/************************************************************************************************************************************/

sudokuMatrix();
colCheck(col_1);
rowCheck(row_1);
 






return 0; 
}