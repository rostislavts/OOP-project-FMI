#ifndef __CELL__H
#define __CELL__H

#include "Formula.h"

#include <iostream>

class Table;

class Cell {
public:
	Cell();
	Cell(int indexOfRow, int indexOfCol);
	virtual ~Cell() {}

	void setIndexOfRow(int row);
	void setIndexOfCol(int col);

	int getIndexOfRow() const { return this->indexOfRow; }
	int getIndexOfCol() const { return this->indexOfCol; }

	virtual int getLengthOfData() const;
	virtual double getValue() const;

	virtual Cell* clone() = 0;
	
	virtual void print(std::ostream& os = std::cout) const = 0;

private:
	int indexOfRow;
	int indexOfCol;
};

#endif