#include "StoreSudoku.h"

StoreSudoku::StoreSudoku(int numberOfLines)
{
	m_sudokuSize = numberOfLines;
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
				m_sudokuArray[i][j]=output[j];
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
			cout << m_sudokuArray[i][j] << "|";
		}
		cout << endl << "------------------" << endl;
	}
}
char StoreSudoku::sudokuGetElement(Row number, Column character)
{
	m_sudokuVerifyRow(number);
	m_sudokuVerifyColumn(character);
	return m_sudokuArray[number-1][character-97];
}
void StoreSudoku::sudokuSetElement(Row number, Column character, char elemNumber) //character and element needs to be enclosed in ' '
{
	m_sudokuVerifyRow(number);
	m_sudokuVerifyColumn(character);
	m_sudokuVerifyElement(elemNumber);
	m_sudokuArray[number-1][character-97]=elemNumber;
	m_itr = m_sudokuConstraintsArray[number-1][character-97].begin();
	m_sudokuConstraintsArray[number-1][character-97].erase(*m_itr);
}

bool StoreSudoku::sudokuElementInBox(Row number, Column character, char elemNumber) //input elemNumber enclosed by ' '
{
	m_sudokuVerifyRow(number);
	m_sudokuVerifyColumn(character);
	m_sudokuVerifyElement(elemNumber);
	int rowsTop;
	int rowsBot;
	int colsLeft;
	int colsRight;
	//this first if clause sets the boundaries for rows
	if (number >= 1 && number < 4)
	{
		rowsBot = 0;
		rowsTop = 2;
	}
	else if (number > 4 && number < 8)
	{
		rowsBot = 3;
		rowsTop = 5;
	}
	else if (number > 7 && number < 10)
	{
		rowsBot = 6;
		rowsTop = 8;
	}

	if (character > 96 && character < 100)
	{
		colsLeft = 0;
		colsRight = 2;
	}
	else if (character > 99 && character < 104)
	{
		colsLeft = 3;
		colsRight = 5;
	}
	else if (character > 103 && character < 107)
	{
		colsLeft = 6;
		colsRight = 8;
	}

	for (int i = rowsBot; i <= rowsTop; i++)
	{
		for (int j = colsLeft; j <= colsRight; j++)
		{
			if (elemNumber == m_sudokuArray[i][j])
			{
				return true;
			}
		}
	}
	return false;
}
bool StoreSudoku::sudokuElementInRow(Row number, char elemNumber) //input elemNumber enclosed by ' '
{
	m_sudokuVerifyRow(number);
	m_sudokuVerifyElement(elemNumber);
	for (int i = 0; i < m_sudokuSize; i++)
	{
		if (elemNumber == m_sudokuArray[number-1][i])
		{
			return true;
		}
	}
	return false;
}
bool StoreSudoku::sudokuElementInCollumn(Column character, char elemNumber) //input character & elemNumber enclosed by ' '
{
	m_sudokuVerifyColumn(character);
	m_sudokuVerifyElement(elemNumber);
	for (int i = 0; i < m_sudokuSize; i++)
	{
		if (elemNumber == m_sudokuArray[i][character-97])
		{
			return true;
		}
	}
	return false;
}

bool StoreSudoku::sudokuCheckElement(Row number, Column character)
{
	m_sudokuVerifyRow(number);
	m_sudokuVerifyColumn(character);
	if (m_sudokuArray[number-1][character-97] != '0')	//This checks for the case that the element has already been filled out
	{
		return false;
	}
	bool check = true; //this condition assumes that the element is NOT inside of the box/row/col
	for (m_itr = m_sudokuConstraintsArray[number-1][character-97].begin(); m_itr != m_sudokuConstraintsArray[number-1][character-97].end(); m_itr++)
	{
		if (sudokuElementInBox(number, character, *m_itr) == true || sudokuElementInCollumn(character, *m_itr) == true || sudokuElementInRow(number, *m_itr) == true)
		{//This if statement can be optimized by separating and applying the remove code to each other member of the box/row/col
			//if element is inside of the box/row/col
			check = false; //the element is also seen in the box/row/col
			m_itrHold = *m_itr;
			m_itr = m_itr = m_sudokuConstraintsArray[number-1][character-97].begin();
			if(sudokuRemoveConstraint(number, character, m_itrHold) == true)
			{
				m_itr = m_sudokuConstraintsArray[number-1][character-97].begin();
				sudokuSetElement(number, character, m_itrHold);
			}
		}
		else
		{
			m_itr++;
		}
	}
	if (check == false)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void StoreSudoku::sudokuInitializeConstraints(Row number, Column character)
{
	m_sudokuVerifyRow(number);
	m_sudokuVerifyColumn(character);
	
	for (int i = 0; i < m_sudokuSize; i++)
	{
		for (int j = 0; j < m_sudokuSize; j++)
		{
			if (m_sudokuArray[number-1][character-97] == '0')
			{
					for (char k = '1'; k <= '9'; k++)
					{
						m_sudokuConstraintsArray[number-1][character-97].insert(k);
					}
			}
		}
	}
}//This can be optimized
bool StoreSudoku::sudokuRemoveConstraint(Row number, Column character, char elemNumber)
{
	if (sudokuRemainingConstraints(number, character)<1)
	{
		exit(1);
	}
	if (m_itr != m_sudokuConstraintsArray[number-1][character-97].end())
	{
		m_itrSecond = m_sudokuConstraintsArray[number-1][character-97].end();
		m_itrSecond--;
		cout << *m_itr << " con: " << sudokuRemainingConstraints(number, character) << " end: " << *m_itrSecond;
		m_itr = m_sudokuConstraintsArray[number-1][character-97].erase(m_itr);
		cout << ":)" << endl;
	}
	else
	{
		cout << "hello";
		m_itr++;
	}

	if (sudokuRemainingConstraints(number, character)==1)
	{
		return true; //return true will call StoreSudoku to set element
	}
	return false; //false will do nothing
}
int StoreSudoku::sudokuRemainingConstraints(Row number, Column character)
{
	return m_sudokuConstraintsArray[number-1][character-97].size();
}

void StoreSudoku::sudokuElementIterator(Row number, Column character)
{
	m_sudokuVerifyRow(number);
	m_sudokuVerifyColumn(character);
	//sets m_sudokuRow and sudokuColumn to be whatever needs to be worked on
}

void StoreSudoku::m_sudokuVerifyRow(Row number)
{
	if (number < 1 || number > 9)
	{
		cout << "Error, row is invalid" << endl;
		//exit(1);
	}
}
void StoreSudoku::m_sudokuVerifyColumn(Column character)
{
	if ((character < 97) || (character > (97 + m_sudokuSize)))
	{
		cout << "Error, column is invalid" << endl;
		exit(1);
	}
}
void StoreSudoku::m_sudokuVerifyElement(char elemNumber)
{
	if (elemNumber-48 > m_sudokuSize || elemNumber-48 <= 0)
	{
		cout << "Error, element number is invalid" << endl;
		exit(1);
	}
}