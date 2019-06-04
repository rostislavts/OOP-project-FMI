#ifndef __TABLE__H
#define __TABLE__H

#include "GlobalFunctions.h"
#include "Cell.h"
#include "EmptyCell.h"
#include "IntCell.h"
#include "DoubleCell.h"
#include "StringCell.h"
#include "Formula.h"
#include "FormulaCell.h"
#include "Row.h"

class Table {
public:
	Table();
	Table(int rows, int cols);
	~Table();
	Table(Table const& otherT);
	Table& operator=(Table const& otherT);

	Row* getRows() const    { return rows; }
	int getCapacity() const { return capacity; }

	void addCell(Cell* cell);

	void print(std::ostream& os = std::cout) const;
	void edit(int row, int col, const char* str);

	Formula createFormula(const char* str);

private: // methods
	void setTableWithEmptyCells();
	void setCapacity(int capacity);

	void doCopy(Table const& otherT);
	void doDelete();
	void resize(int index);
	bool needResize(int index);

	bool isValidEdit(int row, int col, const char* str);
	int checkDataTypeID(const char* str); // returns dataTypeID
	int getMaxNumberOfCols() const;
	void fillArrWithMaxLengthOfEachCol(int* arr, int sizeOfArr) const;
	int getIndexOfOperationInFormula(const char* str);
	void createAndAddCell(int row, int col, const char* str, int dataTypeID);

private:
	Row* rows;
	int capacity; // rowsCapacity
};

#endif