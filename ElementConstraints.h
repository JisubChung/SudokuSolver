#ifndef ELEMENTCONSTRAINTS_H
#define ELEMENTCONSTRAINTS_H

#include <iostream>
#include <set>
#include "StoreSudoku.h"

using namespace std;
typedef int Row;	//NOT 0-ordered
typedef int Column;	//THIS ACCEPTS LOWER CASE ONLY

//An individual ElementConstraints object will be created for each empty element
//that holds the numbers that the element could be

class ElementConstraints
{
public:
	ElementConstraints();
	~ElementConstraints(void);

	void constraintsAdd(char elemNumber);
	void constraintRemove(int elemNumber);

	void constraintListAll();

	int constraintNumRemain();
	
private:
	set<char> options;
	
};

#endif