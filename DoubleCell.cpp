#include "DoubleCell.h"
#include "GlobalFunctions.h"

DoubleCell::DoubleCell() {
	setData(0);
}

DoubleCell::DoubleCell(int indexOfRow, int indexOfCol, double data) : Cell(indexOfRow, indexOfCol) {
	setData(data);
}

void DoubleCell::setData(double data) {
	this->data = data;
}

int DoubleCell::getLengthOfData() const {
	return getLength(getData());
}

double DoubleCell::getValue() const {
	return getData();
}

DoubleCell* DoubleCell::clone() {
	return new DoubleCell(*this);
}

void DoubleCell::print(std::ostream& os) const {
	os << getData();
}