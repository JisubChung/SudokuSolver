#include "ElementConstraints.h"

ElementConstraints::ElementConstraints(void)
{
	for (char i = '1'; i <= '9'; i++)
	{
		m_options.insert(i);
	}
	//for now implementing the easiest case
	//will optimize code later
}

ElementConstraints::~ElementConstraints(void)
{
}

bool ElementConstraints::constraintRemove(char elemNumber)
{
	if (constraintNumRemain()<1)
	{
		exit(1);
	}
	m_options.erase(elemNumber);
	if (constraintNumRemain()==1)
	{
		return true; //return true will call StoreSudoku to set element
	}
	return false; //false will do nothing
}

void ElementConstraints::constraintListAll()
{
	m_itr = m_options.begin();
	while (m_itr != m_options.end())
	{
		cout << *m_itr;
		m_itr++;
	}
}
char ElementConstraints::constraintLast()
{
	m_itr = m_options.begin();
	return *m_itr;
}

int ElementConstraints::constraintNumRemain()
{
	return m_options.size();
}