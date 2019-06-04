#ifndef __COMMANDS__H
#define __COMMANDS__H

#include "Table.h"
#include <string>

const int MAX_LENGTH_OF_COMMAND = 50;

class Commands {
public:
	Commands(const char* command = "");

	void setCommand(const char* command);
	void setfileName(std::string fileName);
	const char* getCommand() const  { return this->command; }
	std::string getfileName() const { return this->fileName; }

	void open(std::string fileName);
	void close();
	void save();
	void saveAs(std::string fileName);
	void exit();
	void print();
	void edit(int row, int col, std::string str);

private:
	void removeSpaces(std::string& str);
	std::string readToComaAndErase(std::string& str);
	int getMaxIndexOfColOfCurrRow(std::string row);
	void removeQuotes(std::string& str);
	void createAndAddCurrCell(std::string currentCell, int indexOfRows, int indexOfCols);

private:
	Table table;
	char command[MAX_LENGTH_OF_COMMAND];
	std::string fileName = "";
};


#endif
