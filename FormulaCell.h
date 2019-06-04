#ifndef __FORMULACELL__H
#define __FORMULACELL__H

#include "Cell.h"
#include "Formula.h"

class FormulaCell : public Cell {
public:
	FormulaCell(int indexOfRow, int indexOfCol, Formula data, Table& table);

	void setData(Formula data);

	Formula getData() const { return this->data; }

	int getLengthOfData() const;
	double getValue() const;

	FormulaCell* clone();

	void print(std::ostream& os = std::cout) const; 
	
private:
	bool isValidFormulaCell() const;

	int getIndexOfCInReference(const char* operand) const; // 'C' 
	int getRowFromReference(const char* operand) const;
	int getColFromReference(const char* operand) const;
	
	double calculateFormula(Formula& formula) const;
	double calculateOperand(const char* operand) const;

private:
	Formula data;
	Table& table;
};

#endif