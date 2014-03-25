#include "sudoku.h"

using namespace std;

sudoku::sudoku(int inputSize)
{
	int m_sudokuSize = inputSize;
	int ** m_sudokuPuzzle = new int * [m_sudokuSize];
	for (int i = 0; i < m_sudokuSize; i++)
	{
		m_sudokuPuzzle[i] = new int[m_sudokuSize];
	}
}

sudoku::~sudoku()
{
	for (int i = 0; i < m_sudokuSize; i++)
	{
		delete [] m_sudokuPuzzle[i];
	}
	delete [] m_sudokuPuzzle;
}
