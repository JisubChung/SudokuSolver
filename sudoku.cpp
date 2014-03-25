#include "sudoku.h"

using namespace std;

sudoku::sudoku(int inputSize, string &fileName)
{
	m_sukuSize = inputSize;
	int ** m_sukuPuzzle = new int * [m_sukuSize];
	for (int i = 0; i < m_sukuSize; i++)
	{
		m_sukuPuzzle[i] = new int[m_sukuSize];
	}
	//m_sukuFill(fileName);
	
}

sudoku::~sudoku()
{
	for (int i = 0; i < m_sukuSize; i++)
	{
		cout << i << "<--i size-->" << m_sukuSize << endl;
		delete [] this->m_sukuPuzzle[i];
	}
	delete [] m_sukuPuzzle;
}

int sudoku::m_sukuFill(string &fileName)
{
	ifstream sukuFile;
	sukuFile.open(fileName.c_str(), ios::in);
	if (!sukuFile.is_open())
	{
		cout << "File not found";
		return (-1);
	}
	char * sukuLine = new char[m_sukuSize];
	for (int i = 0; !sukuFile.eof(); i++)
	{
		sukuFile >> sukuLine;
		cout << sukuLine;
		for (int j = 0; j < m_sukuSize; j++)
		{
			m_sukuPuzzle[i][j] = sukuLine[j]-'0';
			cout << i << " " << j << endl;
		}
	}
	sukuFile.close();
	return 0;
}