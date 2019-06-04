#include "Row.h"

#include <iostream>

Row::Row() {
	setCapacity(1);
	rowCells = new Cell*[capacity]; // only 1 cell !!!
	setRowWithEmptyCells();
}

Row::Row(int columns) {
	setCapacity(columns);
	rowCells = new Cell*[capacity];
	setRowWithEmptyCells();
}

Row::~Row() {
	doDelete();
}

Row::Row(Row const& otherR) {
	doCopy(otherR);
}

Row& Row::operator=(Row const& otherR) {
	if(this != &otherR) {
		doDelete();
		doCopy(otherR);
	}
	return *this;
}

void Row::setRowWithEmptyCells() {
	for(int i = 0; i < capacity; i++) {
		rowCells[i] = new EmptyCell;
	}
}

void Row::setCapacity(int capacity) {
	this->capacity = capacity;
}

void Row::addCell(Cell* cell) {
	int index = cell->getIndexOfCol();
	bool isValidIndex = index >= 0;
	if (!isValidIndex) {
		return;
	}
	if(needResize(index)) {
		resize(index);
	}
	delete[] rowCells[index];
	rowCells[index] = cell;
}

void Row::print(std::ostream& os) {
	for (int i = 0; i < capacity; i++) {
		rowCells[i]->print(os);
	}
}

void Row::doCopy(Row const& otherR) {
	setCapacity(otherR.getCapacity());
	rowCells = new Cell*[capacity];
	setRowWithEmptyCells();

	for(int i = 0; i < capacity; i++) {
		delete[] rowCells[i];
		rowCells[i] = otherR.rowCells[i]->clone();
	}	
}

void Row::doDelete() {
	for(int i = 0; i < capacity; i++) {
		delete[] rowCells[i];
	}
	delete[] rowCells;
}

void Row::resize(int index) {
	int newCapacity = index + 1;
	Cell** tmp = new Cell*[newCapacity];

	for(int i = 0; i < capacity; i++) {
		tmp[i] = rowCells[i];
	}
	for (int i = capacity; i < newCapacity; i++) {
		tmp[i] = new EmptyCell;
	}

	delete[] rowCells;
	setCapacity(newCapacity);
	rowCells = tmp;
}

bool Row::needResize(int index) {
	return index > capacity - 1;
}