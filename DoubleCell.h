#ifndef __DOUBLECELL__H
#define __DOUBLECELL__H

#include "Cell.h"

class DoubleCell : public Cell {
public:
	DoubleCell();
	DoubleCell(int indexOfRow, int indexOfCol, double data);

	void setData(double data);
	
	double getData() const { return this->data; }
	
	int getLengthOfData() const;
	double getValue() const;

	DoubleCell* clone();

	void print(std::ostream& os = std::cout) const;

private:
	double data;
};

#endif