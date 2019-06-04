#include "Cell.h"

Cell::Cell() { // invalid numbers 
	setIndexOfRow(-1);
	setIndexOfCol(-1);	
}

Cell::Cell(int indexOfRow, int indexOfCol) {
	setIndexOfRow(indexOfRow);
	setIndexOfCol(indexOfCol);
}

void Cell::setIndexOfRow(int row) {
	this->indexOfRow = row;
}

void Cell::setIndexOfCol(int col) {
	this->indexOfCol = col;
}

int Cell::getLengthOfData() const {
	return -1; // invalid
}

double Cell::getValue() const {
	return 0;
}