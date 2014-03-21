#ifndef STORESUDOKU_H
#define STORESUDOKU_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "ElementConstraints.h"

using namespace std;
typedef int Row;	//NOT 0-ordered
typedef int Column;	//THIS ACCEPTS LOWER CASE ONLY

class StoreSudoku
{
public:
	StoreSudoku();
	StoreSudoku(int NumberOfLines);
	~StoreSudoku();

	//These are the generic mutator and accessors of the sudoku ds
	void sudokuGetAll();
	char sudokuGetElement(Row number, Column character);
	void sudokuSetElement(Row number, Column character, char element);

	//These functions report if "elemNumber" is inside of the Box/Row/Col
	//This is done so that sudokuCheckElement can compare the constraints to elements in contact
	//These will be called Reporter Functions
	bool sudokuElementInBox(Row number, Column character, char elemNumber);
	bool sudokuElementInRow(Row number, char elemNumber);
	bool sudokuElementInCollumn(Column character, char elemNumber);

	bool sudokuCheckElement(Row number, Column character);
	void sudokuCreateConstraints();

	void sudokuElementIterator(Row number, Column character);

private:
	int m_sudokuSize;
	char m_sudokuArray[9][9];
	int m_sudokuRow;
	int m_sudokuColumn;

	//error catches
	//These are here in the case a bad input is called into a function
	void sudokuCheckRow(Row number);
	void sudokuCheckColumn(Column character);
	void sudokuCheckElement(char elemNumber);
};

#endif