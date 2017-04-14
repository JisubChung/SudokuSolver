#include <stdbool.h>
#include <stdio.h>


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

/*
 * The following three functions will go through each row, col, or box
 * to see if num will fit in multiple cells.
 * i.e. if you CAN put only one Num in row, col, or box then TRUE
*/
bool oneFitInRow(int row, int num, int * puzzle) {
	bool oneFit = false;

	int i = row*9, j = i+9, k = 0;
	while(!oneFit && i < j) {
		if(puzzle[i] == 0){
			if(!isThereNumInCol(i%9,num,puzzle) && !isThereNumInBox(row,i%9,num,puzzle)) {
				k++;
				if(k > 1) {
					break;
				}
			}
		}
		i++;
	}
	if (k == 1) {
		oneFit = true;
	}
	return oneFit;
}
bool oneFitInCol(int col, int num, int * puzzle) {
	bool oneFit = true;

	int i = col, j = i+81, k = 0;
	while(oneFit && i < j) {
		if(puzzle[i] == 0){
			if(!isThereNumInRow(i/9,num,puzzle) && !isThereNumInBox(i/9,col,num,puzzle)) {
				k++;
				if(k > 1) {
					oneFit = false;
					break;
				}
			}
		}
		i+=9;
	}
	return oneFit;
}
bool oneFitInBox(int row, int col, int num, int * puzzle) {
	bool oneFit = true;
	return oneFit;
}

// these check if num is in the row, col, or box
bool isThereNumInRow(int row, int num, int * puzzle) {
	bool numInRow = false;
	int i = row*9, j = i+9;
	while(i < j) {
		if(puzzle[i] == num){
			numInRow = true;
			break;
		}
		i++;
	}
	return numInRow;
}
bool isThereNumInCol(int col, int num, int * puzzle) {
	bool numInCol = false;
	int i = col, j = i+72;
	while(i < j) {
		if(puzzle[i] == num){
			numInCol = true;
			break;
		}
		i+=9;
	}
	return numInCol;
}
bool isThereNumInBox(int row, int col, int num, int * puzzle) {
	bool numInBox = false;
	int i = 0, r = (row/3)*3, c = (col/3)*3;
	while(i < 9) {
		if(puzzle[((r*9)+(9*(i/3)))+(c+(i%3))] == num){
			numInBox = true;
			break;
		}
		i++;
	}
	return numInBox;
}

void solve(int * puzzle) {
}
