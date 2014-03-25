#ifndef SUDOKU_H
#define SUDOKU_H

#include <fstream>
#include <iostream>

using namespace std;

class sudoku
{
public:
	sudoku(int inputSize);
	~sudoku();

private:
	int m_sudokuSize;
	int **m_sudokuPuzzle;
};

#endif