#include <iostream>
#include <fstream>
#include "StoreSudoku.h"

using namespace std;
typedef int Row;		//using these typedefs to reduce confusion
typedef int Column;

int main()
{
	int nine = 9;
	StoreSudoku ab(nine);
	//ab.sudokuGetAll();
	ab.sudokuSetElement(0,'i','3');
	cout << ab.sudokuGetElement(0,'i') <<endl;
	cout << ab.sudokuElementInRow(0,'3') << endl;
	cout << ab.sudokuElementInCollumn('a','7') << endl;
	int x;
	cin >> x;
	return 0;
}