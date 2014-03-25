#include <iostream>
#include "StoreSudoku.h"

using namespace std;
typedef int Row;	//NOT 0-ordered
typedef int Column;	//THIS ACCEPTS LOWER CASE ONLY, -97

int main()
{
	StoreSudoku ab(9);
	ab.sudokuGetAll();
	//7c is 1
	ab.sudokuInitializeConstraints(5,'e');
	ab.sudokuCheckElement(5,'e');
	
	
	int x;
	cin >> x;
	return 0;
}