#include "sudoku.h"

using namespace std;

sudoku::sudoku(int inputSize, string &fileName)
	:m_sukuPuzzle(inputSize, std::vector<int>(inputSize, 0))
{
	m_sukuSize=inputSize;
	m_sukuFill(fileName);

}

sudoku::~sudoku()
{
}

void sudoku::sukuSet(Row x, Column y, int z) //ROW & COLUMN ARE NOT 0-ORDERED
{
	m_sukuPuzzle[x-1][y-1] = z;
}
void sudoku::sukuPrint()
{
	for (int i = 0; i < m_sukuSize; i++)
	{
		for (int j = 0; j < m_sukuSize; j++)
		{
			cout << m_sukuPuzzle[i][j];
			if (j < m_sukuSize-1)
			{
				cout << ", ";
			}
		}
		cout << endl;
	}
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
	Row x = 1;
	Column y = 1;
	int count = 0;
	//int numOfBlanks = 0;
	for (string line; getline(sukuFile, line, ',') || count<(m_sukuSize);)
	{
		int result;
		stringstream convert(line);
		if (!(convert >> result))
		{
			result = 0;
		}
		//if (result != 0)
		//{
		//	numOfBlanks++;
		//}
		sukuSet(x,y,result);
		if (y/m_sukuSize == 1 && y%m_sukuSize == 0)
		{
			x++;
			y=0;
			count++;
		}
		y++;
	}
	sukuFile.close();
	return 0;
	//return numOfBlanks;
}
int sudoku::m_ONCFill()
{

}