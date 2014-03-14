#include <iostream>
#include <fstream>
#include "StoreSudoku.h"

using namespace std;

int main()
{
	StoreSudoku a(9);
	cout << endl;
	a.printSudoku();
	int x;
	cin >> x;
	return 0;
}