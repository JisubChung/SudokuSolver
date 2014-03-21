#include <iostream>
#include <fstream>
#include "StoreSudoku.h"

using namespace std;
typedef int Row;	//note that Row is NOT 0-ordered
typedef int Column;

int main()
{
	StoreSudoku ab(9);
	//ab.sudokuGetAll();
	cout << "bvbbbbbbbb";
	ab.sudokuSetElement(3,97,'3');
	cout << "aaaaaaaaaa";
	cout << ab.sudokuGetElement(1,'i') <<endl;
	cout << ab.sudokuElementInRow(1,'3') << endl;
	cout << ab.sudokuElementInCollumn('b','7') << endl;
	int x;
	cin >> x;
	return 0;
}