#include "Table.h"

#include <stdio.h>
#include <iostream>
#include <cstring>

#include <sstream>
#include <iomanip>
#include <cmath>


Table::Table() {
	setCapacity(1);
	rows = new Row[capacity]; // only 1 row !!!
	setTableWithEmptyCells();
}

Table::Table(int rows, int cols) {
	setCapacity(rows);
	this->rows = new Row[capacity];
	for(int i = 0; i < capacity; i++) {
		this->rows[i].setCapacity(cols);
	}
	setTableWithEmptyCells();
}

Table::~Table() {
	doDelete();
}

Table::Table(Table const& otherT) {
	doCopy(otherT);
}

Table& Table::operator=(Table const& otherT) {
	if(this != &otherT) {
		doDelete();
		doCopy(otherT);
	}
	return *this;
}

void Table::setTableWithEmptyCells() {
	for(int i = 0; i < capacity; i++) {
		rows[i].setRowWithEmptyCells();
	}
}

void Table::setCapacity(int capacity) {
	this->capacity = capacity;
}

void Table::addCell(Cell* cell) {
	int index = cell->getIndexOfRow();
	bool isValidIndex = index >= 0;
	if (!isValidIndex) {
		return;
	}
	if(needResize(index)) {
		resize(index);
	}
	rows[index].addCell(cell);
}


void Table::print(std::ostream& os) const {
	int maxCapacityOfRow = getMaxNumberOfCols(); // number of cols of the longest row

	int* maxLengthOfCol = new int[maxCapacityOfRow]; // array that stores max length of each col

	fillArrWithMaxLengthOfEachCol(maxLengthOfCol, maxCapacityOfRow);

	int whiteSpacesLength = 0;
	for(int i = 0; i < capacity; i++) {
		for(int j = 0; j < rows[i].getCapacity(); j++) {
			whiteSpacesLength = maxLengthOfCol[j] - rows[i].getRowCells()[j]->getLengthOfData() + 1;

			os << ' ';
			rows[i].getRowCells()[j]->print(os);
			os << std::setw(whiteSpacesLength);
			os << ' ';
			if (os.rdbuf() == std::cout.rdbuf()) {
				os << '|';
			}
			else {
				os << ',';
			}
		}
		os << std::endl;
	}
	delete[] maxLengthOfCol;
}

void Table::edit(int row, int col, const char* str) {
	row--; // The table starts with (1,1), but in the memory it starts with (0,0) !
	col--;

	if(!isValidEdit(row, col, str)) {
		std::cout << "Invalid edit !!!" << 
		"( R" << row + 1 << "C" << col + 1 << " )" << std::endl;
		return; // NO EDIT !!!
	}

	int dataTypeID = checkDataTypeID(str);
	createAndAddCell(row, col, str, dataTypeID);
}

void Table::doCopy(Table const& otherT) {
	setCapacity(otherT.getCapacity());
	rows = new Row[capacity];

	for(int i = 0; i < capacity; i++) {
		rows[i].doCopy(otherT.rows[i]);
	}
}

void Table::doDelete() {
	delete[] rows;
}

void Table::resize(int index) {
	int newCapacity = index + 1;
	Row* tmp = new Row[newCapacity];

	for(int i = 0; i < capacity; i++) { 
		tmp[i] = rows[i]; // Row::operator= 
	}
	doDelete();
	setCapacity(newCapacity);
	rows = tmp;
}

bool Table::needResize(int index) {
	return index > capacity - 1;
}

bool Table::isValidEdit(int row, int col, const char* str) {	
	bool isValidRow   = false;
	bool isValidCol   = false;

	if(row >= 0 ) { 
		isValidRow = true;
	} 
	if(isValidRow) {
		if(col >= 0 ) { 
			isValidCol = true;
		}
	}
	//if(isInteger(str) || isDouble(str) || 
	  //  isString(str) || isFormula(str)) {
		//isValidInput = true;
	//}
	if(isValidRow && isValidCol) {
		return true;
	}
	return false;
}

int Table::checkDataTypeID(const char* str) {
	if(isInteger(str)) {
		return 1;
	}
	if(isDouble(str)) {
		return 2;
	}
	if(isFormula(str)) {
		return 4;
	}
	return 3; // string !
}

int Table::getMaxNumberOfCols() const {
	int maxCapacityOfRow = 0;
	int currentCapacity  = 0;

	for (int i = 0; i < capacity; i++) {
		currentCapacity = rows[i].getCapacity();
		if (currentCapacity > maxCapacityOfRow) {
			maxCapacityOfRow = currentCapacity;
		}
	}
	return maxCapacityOfRow;
}

void Table::fillArrWithMaxLengthOfEachCol(int* arr, int sizeOfArr) const {		
	for (int i = 0; i < sizeOfArr; i++) {
		arr[i] = 0;
	}

	int currentLength = 0;
	for (int i = 0; i < capacity; i++) {
		currentLength = 0;
		for (int j = 0; j < rows[i].getCapacity(); j++) {
			currentLength = rows[i].getRowCells()[j]->getLengthOfData();
			if (currentLength > arr[j]) {
				arr[j] = currentLength;
			}
		}
	}
}

Formula Table::createFormula(const char* str) {
	char* leftOperand  = new char[strlen(str)];
	char* rightOperand = new char[strlen(str)];
	for (int i = 0; i < strlen(str); i++) {
		leftOperand[i]  = '\0';
		rightOperand[i] = '\0';
	}

	char operation;
	int indexOfOperation = getIndexOfOperationInFormula(str);
	operation = str[indexOfOperation];

	int index = 0;
	for (int i = 1; i < indexOfOperation; i++) {
		leftOperand[index] = str[i];
		index++;
	}

	index = 0;
	for (int i = indexOfOperation + 1; str[i]; i++) {
		rightOperand[index] = str[i];
		index++;
	}

	Formula tmp(leftOperand, rightOperand, operation);
	delete[] leftOperand;
	delete[] rightOperand;

	return tmp;
}

int Table::getIndexOfOperationInFormula(const char* str) {
	// str[0] == '='
	for (int i = 1; str[i]; i++) {
		if (isValidFormulaOperation(str[i])) {
			if (i == 1 && isSign(str[i])) { // =+12*34
				continue;
			} // else 
			return i;
		}
	}
	return -1; // invalid index
}

void Table::createAndAddCell(int row, int col, const char* str, int dataTypeID) {
	switch (dataTypeID) {
		case 1: { // IntCell
			int value = atoi(str);
			Cell* tmp = new IntCell(row, col, value);
			addCell(tmp);
			return;
		}
		case 2: { // DoubleCell
			double value = atof(str);
			Cell* tmp = new DoubleCell(row, col, value);
			addCell(tmp);
			return;
		}
		case 3: { // StringCell
			Cell* tmp = new StringCell(row, col, str);
			addCell(tmp);
			return;
		}
		case 4: { // FormulaCell
			Formula tmpF = createFormula(str);
			Cell* tmp = new FormulaCell(row, col, tmpF, *this);  // + *this
			addCell(tmp);
			return;
		}
	}
}
