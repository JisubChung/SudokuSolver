#ifndef STORESUDOKU_H
#define STORESUDOKU_H

#include <iostream>
#include <fstream>
#include <set>

using namespace std;
typedef int Row;	//NOT 0-ordered
typedef int Column;	//THIS ACCEPTS LOWER CASE ONLY, -97

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

	//This function returns true if a constraint was removed
	//Returns false if no constraints were removed
	bool sudokuCheckElement(Row number, Column character);
	//This initializes the constraint array to have all options available
	//for each element, can be heavily optimized.
	//Note: the chars listed as constraints may be better understood as
	//      options that the element can take on
	void sudokuInitializeConstraints(Row number, Column character);
	bool sudokuRemoveConstraint(Row number, Column character, char elemNumber);
	int sudokuRemainingConstraints(Row number, Column character);

	void sudokuElementIterator(Row number, Column character);

private:
	int m_sudokuSize;
	//note, that this is a char array, not an int array
	char m_sudokuArray[9][9];
	int m_sudokuRow;
	int m_sudokuColumn;
	set<char> m_sudokuConstraintsArray[9][9];
	set<char>::iterator m_itr;

	//error catches
	//These are here in the case a bad input is called into a function
	void m_sudokuVerifyRow(Row number);
	void m_sudokuVerifyColumn(Column character);
	void m_sudokuVerifyElement(char elemNumber);
};

#endif