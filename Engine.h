#ifndef __ENGINE__H
#define __ENGINE__H

#include <iostream>
#include <typeinfo>
#include <fstream>
#include <string>
#include <stdio.h>
#include <iomanip>

#include "Cell.h"
#include "EmptyCell.h"
#include "IntCell.h"
#include "DoubleCell.h"
#include "StringCell.h"
#include "FormulaCell.h"
#include "Formula.h"
#include "Table.h"
#include "Row.h"
#include "GlobalFunctions.h"
//#include "Tests.h"
#include "Commands.h"

struct Engine {
	void printCommandList();
	bool isValidFileFormat(std::string str);

	void run();
	void runCommand(const char* command, Commands& cmds);
	void runOpen(Commands& cmds);
	void runSaveAs(Commands& cmds);
	void runEdit(Commands& cmds);

	const char* toSmallLetters(const char* str);
	bool isCapitalLetter(char c);
};

#endif
