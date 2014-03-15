#ifndef STORESUDOKU_H
#define STORESUDOKU_H

#include <iostream>
#include <fstream>

using namespace std;

class StoreSudoku
{
public:
	StoreSudoku();
	StoreSudoku(int NumberOfLines); //NumberOfLines is useless for now, but will be used for dynamic allowcation of puzzle size
	~StoreSudoku();

	void sudokuPrintAll();
	void virtual sudokuPrint(); //This will be an inherited function that can be defined for row/box/column

	//char sudokuPrintElement(char column, int row);
	//void sudokuPrintColumn(char column);
	//void sudokuPrintRow(int row);
	//void sudokuPrintBox(char column, int row);

private:
	int sudokuSize;
	char sudokuArray[9][9]; //currently using a static array, will implement a dynamically sized array later
};

#endif