#ifndef STORESUDOKU_H
#define STORESUDOKU_H

#include <iostream>
#include <fstream>

using namespace std;

class StoreSudoku
{
public:
	StoreSudoku();
	StoreSudoku(int NumberOfLines); //NumberOfLines is useless now, but will be used for dynamic allowcation of puzzle size
	~StoreSudoku();

	void printSudoku();

private:
	int sudokuSize;
	char sudokuArray[9][9]; //currently using a static array, will implement a dynamically sized array later
};

#endif