#ifndef SUDOKU_H
#define SUDOKU_H

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
typedef int Row;	//NOT 0-ORDERED
typedef int Column;	//NOT 0-ORDERED

class sudoku
{
public:
	//initializes a blank nxn sudoku puzzle
	sudoku(int inputSize, string &fileName);
	~sudoku();

	void sukuSet(Row x, Column y, int z);
	void sukuPrint();
	


private:
	int m_sukuSize;
	vector<vector<int>> m_sukuPuzzle;
	vector<vector<int>> m_ONC;
	//-FUNCTION: Fills known puzzle elements
	//-TODO: add a check to make sure length matches m_sudokuSize
	int m_sukuFill(string &fileName); 
	int m_ONCFill();
};

#endif