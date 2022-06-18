#ifndef SUDOKU_H
#define SUDOKU_H

// Macros for MINIGRIDSIZE
#ifndef MINIGRIDSIZE
#define MINIGRIDSIZE 3
#endif
#define SIZE ((MINIGRIDSIZE)*(MINIGRIDSIZE))

//Returns a 2D array from an input file containing the Sudoku in space separated format (empty cells are 0)
int **readInput(char *);

/*Checks if solution is a valid solution to original one  
i.e. all originally filled cells match, and that solution is a valid grid*/
int checkValid(int **, int **);

// Produces solution to the puzzle.
int **solSudoku(int **);

#endif
