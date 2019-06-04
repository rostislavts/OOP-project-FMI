#include "EmptyCell.h"

EmptyCell::EmptyCell() {

}

EmptyCell::EmptyCell(int indexOfRow, int indexOfCol) : Cell(indexOfRow, indexOfCol) {

}

int EmptyCell::getLengthOfData() const {
	return 0;
}

double EmptyCell::getValue() const {
	return 0;
}

EmptyCell* EmptyCell::clone() {
	return new EmptyCell(*this);
}

void EmptyCell::print(std::ostream& os) const {
	os << "";
}