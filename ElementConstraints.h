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

//I made a bit of an oversight when making this class,
//rather than using constraints it would have been better
//to use options, as these represent what the element,
//CAN be rather than what it cannot be.

class ElementConstraints
{
public:
	ElementConstraints();
	~ElementConstraints(void);

	//true: only one option remains
	//false: more than one option remains
	bool constraintRemove(char elemNumber);

	void constraintListAll();
	char constraintLast();

	int constraintNumRemain();
	
private:
	set<char> m_options;
	set<char>::iterator m_itr;
};

#endif