#ifndef STORESUDOKU_H
#define STORESUDOKU_H

#include <iostream>
#include <fstream>

using namespace std;
typedef int Row;		//NOT 0-ordered
typedef int Column;	//THIS ACCEPTS LOWER CASE ONLY

class StoreSudoku
{
public:
	StoreSudoku();
	StoreSudoku(int NumberOfLines);
	~StoreSudoku();

	void sudokuGetAll();
	char sudokuGetElement(Row number, Column character);

	void sudokuSetElement(Row number, Column character, char element);

	bool sudokuCheckElement(Row number, Column character);

	bool sudokuElementInBox(Row number, Column character, char elemNumber);
	bool sudokuElementInRow(Row number, char elemNumber);
	bool sudokuElementInCollumn(Column character, char elemNumber);

	void sudokuElementIterator(Row number, Column character);

private:
	int sudokuSize;
	char sudokuArray[9][9];
	int sudokuRow;
	int sudokuColumn;

	//error catches
	void sudokuCheckRow(Row number);
	void sudokuCheckColumn(Column character);
	void sudokuCheckElement(char elemNumber);
};

#endif