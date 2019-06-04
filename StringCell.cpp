#include "StringCell.h"
#include "GlobalFunctions.h"
#include <cstring>

StringCell::StringCell() {
	setData("");
}

StringCell::StringCell(int indexOfRow, int indexOfCol, const char* data) : Cell(indexOfRow, indexOfCol) {
	setData(data);
}

StringCell::StringCell(StringCell const& otherCell) {
	doCopy(otherCell);
}

StringCell& StringCell::operator=(StringCell const& otherCell) {
	if(this != &otherCell) {
		doDelete();
		doCopy(otherCell);
	}
	return *this;
}

StringCell::~StringCell() {
	doDelete();
}

void StringCell::setData(const char* data) {
	const int LENGTH = strlen(data);
	this->data = new char[LENGTH + 1];
	strcpy_s(this->data, LENGTH + 1, data);
}
	
int StringCell::getLengthOfData() const {
	return strlen(getData());
}

double StringCell::getValue() const {
	if (isInteger(getData())) {
		return atoi(getData());
	}
	if (isDouble(getData())) {
		return atof(getData());
	} // else
	return 0;
}

StringCell* StringCell::clone() {
	return new StringCell(*this);
}

void StringCell::print(std::ostream& os) const {
	if (os.rdbuf() != std::cout.rdbuf()) {
		os << '\"' << getData() << '\"';
	}
	else {
		os << getData();
	}
}

void StringCell::doCopy(StringCell const& otherCell) {
	setIndexOfRow(otherCell.getIndexOfRow());  
	setIndexOfCol(otherCell.getIndexOfCol());

	const int LENGTH = strlen(otherCell.getData());
	this->data = new char[LENGTH + 1];
	strcpy_s(this->data, LENGTH + 1, otherCell.getData());
}

void StringCell::doDelete() {
	delete[] this->data;
}