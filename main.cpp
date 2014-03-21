#include <iostream>
#include "StoreSudoku.h"
#include "ElementConstraints.h"

using namespace std;
typedef int Row;	//NOT 0-ordered
typedef int Column;	//THIS ACCEPTS LOWER CASE ONLY

int main()
{
	StoreSudoku ab(9);
	ab.sudokuGetAll();
	ElementConstraints bc;
	bc.constraintListAll();
	bc.constraintRemove('9');
	cout << endl;
	bc.constraintListAll();
	cout << endl;
	cout << bc.constraintNumRemain() << endl;
	for (char i = '2'; i < '9'; i++)
	{
		cout << bc.constraintRemove(i) << endl;
	} 
	cout << endl;
	bc.constraintListAll();
	cout << endl << bc.constraintLast();
	int x;
	cin >> x;
	return 0;
}