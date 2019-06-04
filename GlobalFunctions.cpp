#include "GlobalFunctions.h"
#include <cstring>
#include <string>

bool isSign(char c) {
	return c == '+' || c == '-';
}

bool isDigit(char c) {
	return '0' <= c && c <= '9';
}

bool isDot(char c) {
	return c == '.';
}

bool isInteger(const char* str) {
	for (int i = 0; str[i]; i++) {
		if (i == 0 && !isDigit(str[i])) {
			if (isSign(str[i])) {
				continue;
			}
			return false;
		}
		if (!isDigit(str[i])) {
			return false;
		}
	}
	return true;
}

bool isDouble(const char* str) {
	if (isInteger(str)) { // Valid number, without dot
		return false;
	}

	int dotCount = 0;
	bool alreadyReadNumberBeforeDot = false; // 123.___
	bool alreadyReadNumberAfterDot = false; // ___.123

	for (int i = 0; str[i]; i++) {
		if (i == 0 && !isDigit(str[i])) {
			if (isSign(str[i])) {
				continue;
			}
			return false;
		}
		if (!isDigit(str[i])) { // i != 0
			if (isDot(str[i]) && alreadyReadNumberBeforeDot) {
				dotCount++;
				continue;
			}
			return false;
		}
		// isDigit
		alreadyReadNumberBeforeDot = true;
		if (dotCount > 0) {
			alreadyReadNumberAfterDot = true;
		}
	}
	if (dotCount != 1 || !alreadyReadNumberAfterDot) {
		return false;
	}
	return true;
}

bool isString(const char* str) {
	int LENGTH = strlen(str);
	if (str[0] == '\"' && str[LENGTH - 1] == '\"') {
		return true;
	}
	return false;
}

bool isValidFormulaOperation(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool isReference(const char* operand) { // R<T>C<N>
	if (operand[0] != 'R') {
		return false;
	}

	// operand[0] == 'R'
	bool hasCharC = false;
	for (int i = 1; operand[i]; i++) {
		if (!isDigit(operand[i])) {
			if (operand[i] == 'C' && !hasCharC) {
				hasCharC = true;
				continue;
			} // different char or second time 'C'
			return false;
		}
	}
	if (hasCharC) {
		return true;
	}
	// only digits after 'R' ( R<T> )
	return false;
}

bool isValidOperand(const char* operand) {
	return isInteger(operand) || isDouble(operand) || isReference(operand);
}



bool isFormula(const char* str) {
	if (str[0] != '=') {
		return false;
	}

	if (getIndexOfOperation(str) == -1) { // There isn't operation !
		return false;
	} // else
	
	bool isValidLeftOperand = createAndCheckOperand(str, 1, getIndexOfOperation(str));
	bool isValidRightOperand = createAndCheckOperand(str, getIndexOfOperation(str) + 1, strlen(str));

	if (isValidLeftOperand && isValidRightOperand) {
		return true;
	}
	return false;
}

int getIndexOfOperation(const char* str) {
	for (int i = 1; str[i]; i++) {
		if (i == 1 && isSign(str[i])) { // =+12*44 or =-12*34
			continue;
		}
		if (isValidFormulaOperation(str[i])) { // We know that we can have only ONE operation !!!
			return i;
		}
	}
	return -1; // invalid index, there isn't operation !
}

bool createAndCheckOperand(const char* str, int indexFrom, int indexTo) {
	const int MAX_LENGTH = strlen(str);
	char* operand = new char[MAX_LENGTH + 1];

	for (int i = 0; i < MAX_LENGTH + 1; i++) {
		operand[i] = '\0';
	}

	int index = 0;
	for (int i = indexFrom; i < indexTo; i++) {
		operand[index] = str[i];
		index++;
	}
	
	if (isValidOperand(operand)) {
		delete[] operand;
		return true;
	}
	delete[] operand;
	return false;
}

int getLength(int x) {
	int counter = 0;
	if (x == 0) {
		return 1;
	}
	if (x < 0) { // signed !!!
		counter++;
	}
	while (x != 0) {
		x /= 10;
		counter++;
	}
	return counter;
}

int getLength(double x) {
	std::string str = std::to_string(x);
	str.erase(str.find_last_not_of('0') + 1, std::string::npos);
	return str.length();
}