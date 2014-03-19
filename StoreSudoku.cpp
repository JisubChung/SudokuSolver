#include "StoreSudoku.h"


StoreSudoku::StoreSudoku(int numberOfLines)
{
	int sudokuSize = numberOfLines;
	cout << sudokuSize << "HELLO";
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
	cout << 97+sudokuSize << endl << sudokuSize << endl;

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

void StoreSudoku::sudokuSetElement(Row number, Column character, char element)
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
}

void StoreSudoku::sudokuElementInBox(Row number, Column character, char elemNumber)
{
	//only checking empty cells
	//for the given char number, check if it's inside of the box
}
void StoreSudoku::sudokuElementInRow(Row number, Column character, char elemNumber)
{
	//only checking empty cells
	//for the given char number, check if it's inside of the row
}
void StoreSudoku::sudokuElementInCollumn(Row number, Column character, char elemNumber)
{
	//only checking empty cells
	//for the given char number, check if it's inside of the collumn
}

void StoreSudoku::sudokuElementIterator(Row number, Column character)
{
	//sets sudokuRow and sudokuColumn to be whatever needs to be worked on
}