#include <iostream>
#include <fstream>
#include "StoreSudoku.h"

using namespace std;
typedef int Row;		//using these typedefs to reduce confusion
typedef int Column;

int main()
{
	StoreSudoku ab(9);
	ab.sudokuGetAll();
	ab.sudokuSetElement(0,0,3);
	Column a = 'a';
	cout << a << endl;
	cout << ab.sudokuGetElement(0,a);
	int x;
	cin >> x;
	return 0;
}