#ifndef STORESUDOKU_H
#define STORESUDOKU_H

#include <iostream>
#include <fstream>

using namespace std;
typedef int Row;		//using these typedefs to reduce confusion
typedef int Column;	//THIS ACCEPTS LOWER CASE ONLY

class StoreSudoku
{
public:
	StoreSudoku();
	StoreSudoku(int NumberOfLines); //NumberOfLines is useless for now, but will be used for dynamic allowcation of puzzle size
	~StoreSudoku();

	void sudokuGetAll();
	char sudokuGetElement(Row number, Column character);

	void sudokuSetElement(Row number, Column character, char element);

	bool sudokuCheckElement(Row number, Column character);

private:
	int sudokuSize;
	char sudokuArray[9][9]; //currently using a static array, will implement a dynamically sized array later
};

#endif