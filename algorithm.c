#include <stdbool.h>

bool isThereNumInRow(int row,int num,int * puzzle);
bool isThereNumInCol(int col,int num,int * puzzle);
bool isThereNumInBox(int row,int col,int num,int * puzzle);
bool oneFitInRow(int row,int num,int * puzzle);
bool oneFitInCol(int col,int num,int * puzzle);
bool oneFitInBox(int row,int col,int num,int * puzzle);
/*
 *  1. A number must go in a cell if it is the only option for a given
 *		row, col, and box
*/

// Case 1
// Fails if there's multiple options for num to fit in row, col, box
bool tryFit(int row, int col, int num, int * puzzle) {
	bool willFit = true;
	// first the most basic check: is num already in row, col, or box
	if(isThereNumInRow(row,num,puzzle) && isThereNumInCol(col,num,puzzle) && isThereNumInBox(row,col,num,puzzle)) {
		willFit = false;
	}
	if(willFit && !oneFitInRow(row,num,puzzle) && !oneFitInCol(col,num,puzzle) && !oneFitInBox(row,col,num,puzzle)) {
		willFit = false;
	}
	return willFit;
}

/* The following three functions will go through each row, col, or box
 * to see if num will fit in multiple cells.
*/
bool oneFitInRow(int row, int num, int * puzzle) {
	bool oneFit = true;

	// look at row for cell[s] to (eventually) place num
	int i = row*9, j = i+9;
	while(i < j) {
		if(puzzle[row*9] == 0){
			
		}
		i++;
	}
	return oneFit;
}
bool oneFitInCol(int col, int num, int * puzzle) {
	bool oneFit = true;
	return oneFit;
}
bool oneFitInBox(int row, int col, int num, int * puzzle) {
	bool oneFit = true;
	return oneFit;
}

// these check if num is in the row, col, or box
bool isThereNumInRow(int row, int num, int * puzzle) {
	bool numInRow = true;
	int i = row, j = i+9;
	while(i < j) {
		if(puzzle[i] == num){
			numInRow = false;
			break;
		}
		i++;
	}
	return numInRow;
}
bool isThereNumInCol(int col, int num, int * puzzle) {
	bool numInCol = true;
	int i = col, j = i+72;
	while(i < j) {
		if(puzzle[i] == num){
			numInCol = false;
			break;
		}
		i+=9;
	}
	return numInCol;
}
bool isThereNumInBox(int row, int col, int num, int * puzzle) {
	bool numInBox = true;
	int i = 0, r = (row/3)*3, c = (col/3)*3;
	while(i < 9) {
		if(puzzle[((r*9)+(i/3))+(c+(i%3))] == num){
			numInBox = false;
			break;
		}
		i++;
	}
	return numInBox;
}

void solve(int * puzzle) {
}
