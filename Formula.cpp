#include "Formula.h"

#include <cstring>

Formula::Formula() {
	setLeftOperand("");
	setRightOperand("");
	setOperation('\0');
}

Formula::Formula(const char* leftOperand, const char* rightOperand, char operation) {
	setLeftOperand(leftOperand);
	setRightOperand(rightOperand);
	setOperation(operation);
}

Formula::~Formula() {
	doDelete();
}

Formula::Formula(Formula const& other) {
	doCopy(other);
}

Formula& Formula::operator=(Formula const& other) {
	if(this != &other) {
		doDelete();
		doCopy(other);
	}
	return *this;
}

void Formula::setLeftOperand(const char* leftOperand) {
	const int LENGTH = strlen(leftOperand);
	this->leftOperand = new char[LENGTH + 1];
	strcpy_s(this->leftOperand,LENGTH + 1, leftOperand);
	this->leftOperand[LENGTH] = '\0';
}

void Formula::setRightOperand(const char* rightOperand) {
	const int LENGTH = strlen(rightOperand);
	this->rightOperand = new char[LENGTH + 1];
	strcpy_s(this->rightOperand,LENGTH + 1, rightOperand);
	this->rightOperand[LENGTH] = '\0';
}

void Formula::setOperation(char op) {
	this->operation = op;
}

void Formula::doCopy(Formula const& otherF) {
	const int LENGTH_OF_LEFTOPERAND  = strlen(otherF.leftOperand);
	const int LENGTH_OF_RIGHTOPERAND = strlen(otherF.rightOperand);

	this->leftOperand  = new char[LENGTH_OF_LEFTOPERAND + 1];
	this->rightOperand = new char[LENGTH_OF_RIGHTOPERAND + 1];

	strcpy_s(this->leftOperand, LENGTH_OF_LEFTOPERAND + 1, otherF.leftOperand);
	this->leftOperand[LENGTH_OF_LEFTOPERAND] = '\0';

	strcpy_s(this->rightOperand, LENGTH_OF_RIGHTOPERAND + 1, otherF.rightOperand);
	this->rightOperand[LENGTH_OF_RIGHTOPERAND] = '\0';

	setOperation(otherF.getOperation());
}

void Formula::doDelete() {
	delete[] leftOperand;
	delete[] rightOperand;
}