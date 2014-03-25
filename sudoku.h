#ifndef SUDOKU_H
#define SUDOKU_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;
typedef int Row;
typedef int Column;

class sudoku
{
public:
	//initializes a blank nxn sudoku puzzle
	sudoku(int inputSize, string &fileName);
	~sudoku();

	int sukuSet(Row x, Column y, int z);

	

private:
	int m_sukuSize;
	int **m_sukuPuzzle;
	//-FUNCTION: Fills known puzzle elements
	//-TODO: add a check to make sure length matches m_sudokuSize
	int m_sukuFill(string &fileName); 
};

#endif