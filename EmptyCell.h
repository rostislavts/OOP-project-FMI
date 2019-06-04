#ifndef __EMPTYCELL__H
#define __EMPTYCELL__H

#include "Cell.h"

class EmptyCell : public Cell {
public:
	EmptyCell();
	EmptyCell(int indexOfRow, int indexOfCol);

	int getLengthOfData() const;
	double getValue() const;

	EmptyCell* clone();

	void print(std::ostream& os = std::cout) const;

private:
 	// NO DATA
};

#endif