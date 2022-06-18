// How to run the project.
// make.sh 4
// sudoku 2 TestCases/16x16_board/sudoku16_input1


// Libraries defined.
#include <stdio.h>
#include <stdlib.h>
#include "sudoku.c"
#include "sudoku.h"
#include <string.h>
#include <omp.h>

// Number of threads initialised.
int threadCount = 4;

//Returns a 2D array from an input file containing the Sudoku in space separated format (empty cells are 0)
int ** readInput(char *filename){
   FILE *inputFile;
   inputFile = fopen(filename, "r");
   int i, j;
   char dummyline[SIZE+1];
   char dummy;
   int val;
   int *sudokuGrid = (int)malloc(sizeof(int)*SIZE);

   // Initialises the dynamic memory with 0's.
   for (i = 0; i < SIZE; i++){
      sudokuGrid[i] = (int*)malloc(sizeof(int)*SIZE);
      for (j = 0; j < SIZE; j++)
         sudokuGrid[i][j] = 0;
   }
// Initialises dynamically with the input values of the grid.
   for (i = 0; i < SIZE; i++){
      for (j = 0; j < SIZE; j++){
         // Checking if number of rows is less than SIZE 
         if (feof(inputFile)){
            if (i != SIZE){
               printf("The input puzzle has less number of rows than %d. Exiting.\n", SIZE);
               exit(-1);
            }
            }

            fscanf(inputFile, "%d", &val);
            if(val >= 0 && val <= SIZE)
            sudokuGrid[i][j] = val;
         else{
            printf("The input puzzle is not a grid of numbers (0 <= n <= %d) of size %dx%d. Exiting.\n", SIZE, SIZE, SIZE);
            exit(-1);
         }
      }
      // To remove stray \0 at the end of each line.
      fscanf(inputFile, "%c", &dummy); 

      // Checking if row has more elements than SIZE.
      if (j > SIZE){
         printf("Row %d has more number of elements than %d. Exiting.\n", i+1, SIZE);
         exit(-1);
      }
   }
   return sudokuGrid;
}


/*Checks if solution is a valid solution to original one  
i.e. all originally filled cells match, and that solution is a valid grid*/
int checkValid(int **original, int **solution){
   int valuesChecked[SIZE],i,j,k;

   //check all rows
   for (i = 0; i < SIZE; i++){
      for (k = 0; k < SIZE; k++) valuesChecked[k] = 0;
      for (j = 0; j < SIZE; j++){
         if (solution[i][j]==0) return 0;
         if ((original[i][j])&&(solution[i][j] != original[i][j])) {
            printf("Values mismatch at (%d, %d) \n", i, j);
            return 0;
         }
         int v = solution[i][j];
         if (valuesChecked[v-1]==1){
            printf("Repeatition of values %d in row at (%d, %d) \n", v, i, j);
            return 0;
         }
         valuesChecked[v-1] = 1;
      }
   }

   //check all columns
   for (i = 0; i < SIZE; i++){
      for (k = 0; k < SIZE; k++) valuesChecked[k] = 0;
      for (j = 0; j < SIZE; j++){
         int v = solution[j][i];
         if (valuesChecked[v-1]==1){
            printf("Repeatition of values %d in column at (%d, %d) \n", v, j, i);
            return 0;
         }
         valuesChecked[v-1] = 1;
      }
   }

   //check all minigrids
   //check all rows
   for (i = 0; i < SIZE; i = i+MINIGRIDSIZE){
      for (j = 0; j < SIZE; j = j+MINIGRIDSIZE){
         for (k = 0; k < SIZE; k++) valuesChecked[k] = 0;
         int r,c;
         for (r = i; r < i+MINIGRIDSIZE; r++)
            for (c = j; c < j+MINIGRIDSIZE; c++){
               int v = solution[r][c];
               if (valuesChecked[v-1]==1) {
                  printf("repeat of val %d in box at (%d, %d) \n", v, i, j);
                  return 0;
               }
               valuesChecked[v-1] = 1;
            }
      }
   }
   return 1;
}
