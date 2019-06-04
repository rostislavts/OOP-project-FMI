#include "Commands.h"
#include <fstream>

Commands::Commands(const char* command) {
	setCommand(command);
}

void Commands::setCommand(const char* command) {
	strcpy_s(this->command, MAX_LENGTH_OF_COMMAND, command);
}

void Commands::setfileName(std::string fileName) {
	this->fileName = fileName;
}

void Commands::open(std::string fileName) {
	std::ifstream ifs(fileName.c_str());

	if (ifs.fail()) {
		std::cerr << "Eror opening file!!!" << std::endl;
		std::ofstream ofs(fileName.c_str());
		std::cout << "New file " << fileName << " created !" << std::endl;
		ofs.close();
	}
	else {
		std::cout << "Successfully opened " << fileName << std::endl;
	}
	
	setfileName(fileName);

	std::string row;
	std::string currentCell;

	int indexOfRows = 0;
	int maxIndexOfColOfCurrRow = 0;

	while (std::getline(ifs, row)) {
		maxIndexOfColOfCurrRow = getMaxIndexOfColOfCurrRow(row);
		for (int i = 0; i < maxIndexOfColOfCurrRow; i++) {
			currentCell = readToComaAndErase(row);
			removeSpaces(currentCell);
			createAndAddCurrCell(currentCell, indexOfRows, i);
		}
		indexOfRows++;
	}
	ifs.close();
}

void Commands::close() {
	if (fileName != "") {
		std::string copyFileName = fileName;
		setfileName("");
		this->table = Table();

		std::cout << "Successfully closed " << copyFileName << std::endl;
	}
	else {
		std::cerr << "You didn't open a file !" << std::endl;
	}
}

void Commands::save() {
	if (fileName != "") {
		std::ofstream ofs(fileName, std::ios::out | std::ios::trunc);

		table.print(ofs);
		
		std::cout << "Successfully saved " << fileName << std::endl;
		ofs.close();
	}
	else {
		std::cerr << "You didn't open a file !" << std::endl;
	}	
}

void Commands::saveAs(std::string fileName) {
	if (this->fileName != "") {
		std::ofstream ofs(fileName, std::ios::out | std::ios::trunc);

		table.print(ofs);

		std::cout << "Successfully saved " << fileName << std::endl;
		ofs.close();
	}
	else {
		std::cerr << "You didn't open a file !" << std::endl;
	}
}

void Commands::exit() {
	std::cout << "Exiting the program..." << std::endl;
}

void Commands::print() {
	if (fileName != "") {
		table.print();
	}
	else {
		std::cerr << "You didn't open a file !" << std::endl;
	}
}

void Commands::edit(int row, int col, std::string str) {
	if (fileName != "") {
		Cell* cell = new EmptyCell(row - 1, col - 1);
		table.addCell(cell);
		table.edit(row, col, str.c_str());
	}
	else {
		std::cerr << "You didn't open a file !" << std::endl;
	}
}

void Commands::removeSpaces(std::string& str) {
	for (int i = 0; i < str.length(); i++) {
		while(str[i] == ' ') {
			str.erase(str.begin() + i);
		}
	}
}

std::string Commands::readToComaAndErase(std::string& str) {
	std::string resultStr;
	int index;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ',') {
			resultStr = str.substr(0, i);
			index = i;
			break;
		}
	}
	str.erase(0, index + 1);
	return resultStr;
}

int Commands::getMaxIndexOfColOfCurrRow(std::string row) {
	int index = 0;
	for (int i = 0; i < row.length(); i++) {
		if (row[i] == ',') {
			index++;
		}
	}
	return index;
}

void Commands::removeQuotes(std::string& str) {
	str.pop_back();
	str.erase(0, 1);
}

void Commands::createAndAddCurrCell(std::string currentCell, int indexOfRows, int indexOfCols) {
	if (currentCell == "") {
		Cell* cell = new EmptyCell(indexOfRows, indexOfCols);
		table.addCell(cell);
	}
	else if (isInteger(currentCell.c_str())) {
		Cell* cell = new IntCell(indexOfRows, indexOfCols, atoi(currentCell.c_str()));
		table.addCell(cell);
	}
	else if (isDouble(currentCell.c_str())) {
		Cell* cell = new DoubleCell(indexOfRows, indexOfCols, atof(currentCell.c_str()));
		table.addCell(cell);
	}
	else if (isString(currentCell.c_str())) {
		removeQuotes(currentCell);
		Cell* cell = new StringCell(indexOfRows, indexOfCols, currentCell.c_str());
		table.addCell(cell);
	}
	else if (isFormula(currentCell.c_str())) {
		Formula formula = table.createFormula(currentCell.c_str());
		Cell* cell = new FormulaCell(indexOfRows, indexOfCols, formula, table);
		table.addCell(cell);
	}
	else {
		std::cerr << "Unknown data type (R" << indexOfRows + 1 << 'C' << indexOfCols + 1 << ") : ";
		std::cerr << currentCell << std::endl;
	}
}