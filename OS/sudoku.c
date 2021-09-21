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
int boolCol[9] = {0,0,0,0,0,0,0,0,0};
int boolRow[9] = {0,0,0,0,0,0,0,0,0};
int boolSubGrid[9];

pthread_t tid_row[9];
pthread_t tid_col[9];
pthread_t tid_subGrid[9];

/** A structure for rows and columns to be preocessed by index by each thread
 * Indexes are 0 - 8 
 * (<topRow>,<bottomRow>,<lefColumn>,<rightColumn>)
 * **/
typedef struct indexPro{
   int topRow;
   int bottomRow;
   int leftColumn;
   int rightColumn;  
}Indexer;

typedef struct {
    Indexer subSet;
    int i;
}ThreadParam;

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
    printSudokuPuzzle();
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
void *colCheck(void *param){
    ThreadParam *colParams;
    int i;
    Indexer col_;

    colParams = (ThreadParam *)param;
    i = colParams->i;
    col_ = colParams->subSet;

    int colValues[9];
    bool contains = TRUE; 
    
    for(int row = 0; row < 9; row++){
        colValues[row] = sudokuPuzle[row][col_.leftColumn]; 
    }

    qsort(colValues, 9, sizeof(int), compareVals);
    
    int val = 1;
    for(int mover = 0; mover < 9; mover++){
        if(colValues[mover] != val){
            contains = FALSE;
            break;
        }
        val++;
    }
    boolCol[col_.leftColumn] = contains;
}


void *rowCheck(void *param){
    ThreadParam *rowParams;
    int i;
    Indexer row_;

    rowParams = (ThreadParam *)param;
    i = rowParams->i;
    row_ = rowParams->subSet;
    
    int rowValues[9];
    bool contains = TRUE;
    for(int column = 0; column < 9; column++){
        rowValues[column] = sudokuPuzle[row_.topRow][column];
    }

    qsort(rowValues, 9, sizeof(int), compareVals);
    
    int val = 1;
    for(int mover = 0; mover < 9; mover++){
        if(rowValues[mover] != val){
            contains = FALSE;
            break;
        }
        boolRow[row_.topRow] = contains;
        val++;
    }  
}

/** Checks if the given column has all values
 * first sorts array columnValues using std lib qsort
 * */
void *gridCheck(void *param){
    ThreadParam *gridParams;
    int i;
    Indexer grid_;

    gridParams = (ThreadParam *)param;
    i = gridParams->i;
    grid_ = gridParams->subSet;
    int gridValues[9];
    bool contains = TRUE; 
    
    int index = 0;
    for(int row = grid_.topRow; row <= grid_.bottomRow; row++){
        for(int col = grid_.leftColumn; col <= grid_.rightColumn; col++) {
            gridValues[index] = sudokuPuzle[row][col]; 
            index++;
        }
    }

    qsort(gridValues, 9, sizeof(int), compareVals);
    
    int val = 1;
    for(int mover = 0; mover < 9; mover++){
        if(gridValues[mover] != val){
            contains = FALSE;
            break;
        }
        val++;
    }
    boolSubGrid[i] = contains;      
}




int main(){

/** Column struct intialization **/
    Indexer columns[9];

/** Row struct initialization **/
    Indexer rows[9];

/** Sub_Grid struct intialization **/
    Indexer grids[9];
    
/************************************************************************************************************************************/
/** Set Column indexs **/
    for(int col = 0; col < 9; col++) {
        columns[col].topRow = 0;
        columns[col].bottomRow = 8;
        columns[col].leftColumn = col;
        columns[col].rightColumn = col;
    }

    for(int row = 0; row < 9; row++) {
        rows[row].topRow = row;
        rows[row].bottomRow = row;
        rows[row].leftColumn = 0;
        rows[row].rightColumn = 8;
    }

    int currentGrid = 0;
    for(int gridX = 0; gridX < 3; gridX++) {
        for(int gridY = 0; gridY < 3; gridY++) {
            grids[currentGrid].topRow = gridX * 3;
            grids[currentGrid].bottomRow = (gridX * 3) + 2;
            grids[currentGrid].leftColumn = gridY * 3;
            grids[currentGrid].rightColumn = (gridY * 3) +2;
            currentGrid++;
        }
    }
/************************************************************************************************************************************/
    sudokuMatrix();

    


    pthread_t rowThreads[9];
    pthread_t colThreads[9];
    pthread_t gridThreads[9];

    for(int i = 0; i < 9; i++){
        ThreadParam params;
        params.i = i;
        params.subSet = rows[i];
        if(pthread_create(rowThreads + i, NULL, *rowCheck, &params) == 0){
            tid_row[i] = rowThreads[i]; 
        }
        
        pthread_join(rowThreads[i], NULL);
            
    }

    for(int i = 0; i < 9; i++){
        ThreadParam params;
        params.i = i;
        params.subSet = columns[i];
        if(pthread_create(colThreads + i, NULL, *colCheck, &params) == 0){
            tid_col[i] = colThreads[i]; 
        }
        
        pthread_join(colThreads[i], NULL);
            
    }

    for(int i = 0; i < 9; i++){
        ThreadParam params;
        params.i = i;
        params.subSet = grids[i];
        if(pthread_create(gridThreads + i, NULL, *gridCheck, &params) == 0){
            tid_subGrid[i] = gridThreads[i]; 
        }
        
        pthread_join(gridThreads[i], NULL);
            
    }


    return 0; 
}