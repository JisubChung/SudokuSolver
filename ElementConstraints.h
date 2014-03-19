#ifndef ELEMENTCONSTRAINTS_H
#define ELEMENTCONSTRAINTS_H

//an individual ElementConstraints object will be created for each empty element

class ElementConstraints
{
public:
	ElementConstraints(void);
	~ElementConstraints(void);

	void constraintRemove(int number);

	void constraintListAll();

	int constraintNumRemain();
};

#endif