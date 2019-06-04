#ifndef __INTCELL__H
#define __INTCELL__H

#include "Cell.h"

class IntCell : public Cell {
public:
	IntCell();
	IntCell(int indexOfRow, int indexOfCol, int data);

	void setData(int data);

	int getData() const 	{ return this->data; }

	int getLengthOfData() const;
	double getValue() const;

	IntCell* clone();

	void print(std::ostream& os = std::cout) const;

	
private:
	int data;
};

#endif