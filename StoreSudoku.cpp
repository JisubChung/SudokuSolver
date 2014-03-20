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
	if ((character < 97) || (character > (97 + sudokuSize)))
	{
		cout << "Error, column is invalid" << endl;
		return '0';
	}
	else
	{
		return sudokuArray[number][character-97];
	}
}

void StoreSudoku::sudokuSetElement(Row number, Column character, char element) //character and element needs to be enclosed in ' '
{
	sudokuArray[number][character-97]=element;
}

bool StoreSudoku::sudokuCheckElement(Row number, Column character)
{
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
	//only checking empty cells
	//for the given char number, check if it's inside of the box
	return false;
}
bool StoreSudoku::sudokuElementInRow(Row number, char elemNumber) //input elemNumber enclosed by ' '
{
	for (int i = 0; i < sudokuSize; i++)
	{
		if (elemNumber == sudokuArray[number][i])
		{
			return true;
		}
	}
	return false;
}
bool StoreSudoku::sudokuElementInCollumn(Column character, char elemNumber) //input character & elemNumber enclosed by ' '
{
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
	//sets sudokuRow and sudokuColumn to be whatever needs to be worked on
}