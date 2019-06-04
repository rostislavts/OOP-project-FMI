#ifndef __ROW__H
#define __ROW__H

#include "Cell.h"
#include "EmptyCell.h"
#include "IntCell.h"
#include "DoubleCell.h"
#include "StringCell.h"
#include "Formula.h"
#include "FormulaCell.h"

class Row {
public:
	Row();
	Row(int columns);
	~Row();
	Row(Row const& otherR);
	Row& operator=(Row const& otherR);
	
	void setRowWithEmptyCells();
	void setCapacity(int capacity);

	Cell** getRowCells() const 	{ return rowCells; } 
	int getCapacity() const     { return capacity; }

	void addCell(Cell* cell);

	void print(std::ostream& os = std::cout);

	void doCopy(Row const& otherR);
	void doDelete();
	void resize(int index); // index + 1 is the new capacity
	bool needResize(int index); // bigger int (indexOfCol) than capacity in function addCell

private:
	Cell** rowCells;
	int capacity;
};

#endif