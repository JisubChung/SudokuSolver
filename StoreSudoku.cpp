#include "StoreSudoku.h"


StoreSudoku::StoreSudoku(int numberOfLines)
{
	sudokuSize = numberOfLines;
	ifstream sudoku;
	sudoku.open("puzzle.txt");
	char output[10];
	if (sudoku.is_open())
	{
		for (int i = 0; !sudoku.eof(); i++)
		{
			sudoku >> output;
			for (int j = 0; j < numberOfLines; j++)
			{
				sudokuArray[i][j]=output[j];
			}		
		}
	}
	sudoku.close();
}
StoreSudoku::~StoreSudoku(void)
{
}

void StoreSudoku::sudokuGetAll()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << sudokuArray[i][j] << "|";
		}
		cout << endl << "------------------" << endl;
	}
}
char StoreSudoku::sudokuGetElement(Row number, Column character)
{
	sudokuCheckRow(number);
	sudokuCheckColumn(character);
	return sudokuArray[number-1][character-97];
}

void StoreSudoku::sudokuSetElement(Row number, Column character, char elemNumber) //character and element needs to be enclosed in ' '
{
	sudokuCheckRow(number);
	sudokuCheckColumn(character);
	sudokuCheckElement(elemNumber);
	sudokuArray[number-1][character-97]=elemNumber;
}

bool StoreSudoku::sudokuCheckElement(Row number, Column character)
{
	sudokuCheckRow(number);
	sudokuCheckColumn(character);
	//Get a list of all the possible constraints
	//Check those constraints with elements in contact
	//if a constraint matches with another element in contact,
	//then remove that constraint

	//Can be optimized by removing constraint from all elements that share in the box/row/col
	return false;
}

//These functions report if "elemNumber" is inside of the Box/Row/Col
//This is done so that sudokuCheckElement can compare the constraints to elements in contact
bool StoreSudoku::sudokuElementInBox(Row number, Column character, char elemNumber) //input elemNumber enclosed by ' '
{
	sudokuCheckRow(number);
	sudokuCheckColumn(character);
	sudokuCheckElement(elemNumber);
	int rowsTop;
	int rowsBot;
	int colsLeft;
	int colsRight;
	//this first if clause sets the boundaries for rows
	if (number >= 1 && number < 4)
	{
		rowsBot = 1;
		rowsTop = 3;
	}
	else if (number > 4 && number < 8)
	{
		rowsBot = 4;
		rowsTop = 6;
	}
	else if (number > 7 && number < 10)
	{
		rowsBot = 7;
		rowsTop = 9;
	}

	if (character > 96 && character < 100)
	{
		colsLeft = 97;
		colsRight = 99;
	}
	else if (character > 99 && character < 104)
	{
		colsLeft = 100;
		colsRight = 102;
	}
	else if (character > 103 && character < 107)
	{
		colsLeft = 103;
		colsRight = 105;
	}
	return false;
}
bool StoreSudoku::sudokuElementInRow(Row number, char elemNumber) //input elemNumber enclosed by ' '
{
	sudokuCheckRow(number);
	sudokuCheckElement(elemNumber);
	for (int i = 0; i < sudokuSize; i++)
	{
		if (elemNumber == sudokuArray[number-1][i])
		{
			return true;
		}
	}
	return false;
}
bool StoreSudoku::sudokuElementInCollumn(Column character, char elemNumber) //input character & elemNumber enclosed by ' '
{
	sudokuCheckColumn(character);
	sudokuCheckElement(elemNumber);
	for (int i = 0; i < sudokuSize; i++)
	{
		if (elemNumber == sudokuArray[i][character-97])
		{
			return true;
		}
	}
	return false;
}

void StoreSudoku::sudokuElementIterator(Row number, Column character)
{
	sudokuCheckRow(number);
	sudokuCheckColumn(character);
	//sets sudokuRow and sudokuColumn to be whatever needs to be worked on
}

//error catches
void StoreSudoku::sudokuCheckRow(Row number)
{
	if (number < 1 || number > 9)
	{
		cout << "Error, row is invalid" << endl;
		//exit(1);
	}
}
void StoreSudoku::sudokuCheckColumn(Column character)
{
	if ((character < 97) || (character > (97 + sudokuSize)))
	{
		cout << "Error, column is invalid" << endl;
		exit(1);
	}
}
void StoreSudoku::sudokuCheckElement(char elemNumber)
{
	if (elemNumber-48 > sudokuSize || elemNumber-48 < 1)
	{
		cout << "Error, element number is invalid" << endl;
		exit(1);
	}
}