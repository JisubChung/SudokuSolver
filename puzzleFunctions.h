#ifndef PUZZLEFUNCTIONS_H_
#define PUZZLEFUNTIONS_H_
#include <stdbool.h>


int * importPuzzle(char *path);
void printPuzzle(int *puzzle);
bool verifyPuzzle(int * puzzle);
bool verifyPuzzleRow(int * puzzle);
bool verifyPuzzleCol(int * puzzle);
bool verifyPuzzleBox(int * puzzle);

#endif
