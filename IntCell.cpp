#include "IntCell.h"
#include "GlobalFunctions.h"

IntCell::IntCell() {
	setData(0);
}

IntCell::IntCell(int indexOfRow, int indexOfCol, int data) : Cell(indexOfRow, indexOfCol) {
	setData(data);
}

void IntCell::setData(int data) {
	this->data = data;
}

int IntCell::getLengthOfData() const {
	return getLength(getData());
}

double IntCell::getValue() const {
	return getData();
}

IntCell* IntCell::clone() {
	return new IntCell(*this);
}

void IntCell::print(std::ostream& os) const {
	os << getData();
}