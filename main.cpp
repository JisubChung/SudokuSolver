#include <iostream>
#include "sudoku.h"
#include <string>

using namespace std;
typedef int Row;	//NOT 0-ordered
typedef int Column;	//THIS ACCEPTS LOWER CASE ONLY, -97

int main()
{
	string abcd = "puzzle.txt";
	sudoku a(9, abcd);
	cout << endl << endl;
	int x;
	cin >> x;
	return 0;
}