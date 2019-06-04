#include "FormulaCell.h"
#include "GlobalFunctions.h"
#include "Table.h"

#include <cstring>

FormulaCell::FormulaCell(int indexOfRow, int indexOfCol, Formula data, Table& table) :
	Cell(indexOfRow, indexOfCol), table(table) {

	setData(data);	
}

void FormulaCell::setData(Formula data) { 
	this->data = data; // using operator= of class Formula
}

int FormulaCell::getLengthOfData() const {
	if (isValidFormulaCell()) {
		if (getValue() == (int)getValue()) {
			return getLength((int)getValue());
		}
		return getLength(getValue());
	}
	return strlen("ERROR");
}

double FormulaCell::getValue() const {
	Formula formula(data);	
	return calculateFormula(formula);
}

FormulaCell* FormulaCell::clone() {
	return new FormulaCell(*this);
}

void FormulaCell::print(std::ostream& os) const {
	if (os.rdbuf() != std::cout.rdbuf()) {
		os << '=' << data.getLeftOperand() << data.getOperation() << data.getRightOperand();
		return;
	}

	if (isValidFormulaCell()) {
		os << getValue();
		return;
	}
	os << "ERROR";
}


bool FormulaCell::isValidFormulaCell() const {
	Formula formula(data);
	calculateFormula(formula);
	if (!strcmp(formula.getLeftOperand(), "ERROR")) {
		return false;
	}
	return true;
}

double FormulaCell::calculateFormula(Formula& formula) const {
	double leftOperandResult = calculateOperand(formula.getLeftOperand());
	double rightOperandResult = calculateOperand(formula.getRightOperand());

	// calculate
	if (formula.getOperation() == '+') {
		return leftOperandResult + rightOperandResult;
	}
	if (formula.getOperation() == '-') {
		return leftOperandResult - rightOperandResult;
	}
	if (formula.getOperation() == '*') {
		return leftOperandResult * rightOperandResult;
	}
	if (formula.getOperation() == '/') {
		if (rightOperandResult == 0) { // 12/0 !!!
			// ERROR !!!
			formula.setLeftOperand("ERROR");
			formula.setRightOperand("");
			formula.setOperation('\0');
			return 0;
		}
		return leftOperandResult / rightOperandResult;
	}
	if (formula.getOperation() == '^') {
		return pow(leftOperandResult, rightOperandResult);
	}
}

double FormulaCell::calculateOperand(const char* operand) const {
	double operandResult;

	if (!isReference(operand)) {
		// int || double
		if (!strcmp(operand, "ERROR")) {
			return 0;
		} // else

		operandResult = atof(operand);
		return operandResult;
	}

	if (isReference(operand)) {
		int row = getRowFromReference(operand);
		int col = getColFromReference(operand);

		bool isValidRow = true;
		bool isValidCol = true;

		if (row < 0 || row >= table.getCapacity()) {
			isValidRow = false;
		}
		if (isValidRow) {
			if (col < 0 || col >= table.getRows()[row].getCapacity()) {
				isValidCol = false;
			}
		}

		if (!isValidRow || !isValidCol) { // Out of the table !
			operandResult = 0;
		}
		else {
			operandResult = table.getRows()[row].getRowCells()[col]->getValue();
		}
	}
	return operandResult;
}

int FormulaCell::getRowFromReference(const char* operand)  const {
	const int LENGTH = strlen(operand);
	int indexOfC = getIndexOfCInReference(operand);

	int row;

	char* charRow = new char[indexOfC + 1 - 1]; // -1 because of the 'R'
	charRow[indexOfC - 1] = '\0';

	int index = 0;
	for (int i = 1; i < indexOfC; i++) {
		charRow[index] = operand[i];
		index++;
	}

	row = atoi(charRow) - 1; // The table starts with (1,1), but in the memory it starts with (0,0) !
	delete[] charRow;
	return row;
}

int FormulaCell::getColFromReference(const char* operand) const {
	const int LENGTH = strlen(operand);
	int indexOfC = getIndexOfCInReference(operand);

	int col;

	char* charCol = new char[LENGTH - indexOfC]; // R123C1234 
	charCol[LENGTH - indexOfC - 1] = '\0';

	int index = 0;
	for (int i = indexOfC + 1; i < LENGTH; i++) {
		charCol[index] = operand[i];
		index++;
	}

	col = atoi(charCol) - 1; // The table starts with (1,1), but in the memory it starts with (0,0) !
	delete[] charCol;
	return col;
}

int FormulaCell::getIndexOfCInReference(const char* operand) const {
	// operand[0] == 'R'
	for (int i = 1; operand[i]; i++) {
		if (operand[i] == 'C') { // R1232C23
			return i;
		}
	}
}