#include "StoreSudoku.h"


StoreSudoku::StoreSudoku()
{
}

StoreSudoku::StoreSudoku(int numberOfLines)
{
	int sudokuSize = numberOfLines;
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

void StoreSudoku::sudokuPrintAll()
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