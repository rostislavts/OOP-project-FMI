#include "Engine.h"

void Engine::printCommandList() {
	std::cout << std::setw(30) << ' ' << "/==============================================/\n";
	std::cout << std::setw(30) << ' ' << "/                                              /\n";
	std::cout << std::setw(30) << ' ' << "/             LIST OF COMMANDS                 /\n";
	std::cout << std::setw(30) << ' ' << "/                                              /\n";
	std::cout << std::setw(30) << ' ' << "/==============================================/\n";
	std::cout << std::setw(30) << ' ' << "/           open    ->  fileName (.txt)        /\n";
	std::cout << std::setw(30) << ' ' << "/           close                              /\n";
	std::cout << std::setw(30) << ' ' << "/           save                               /\n";
	std::cout << std::setw(30) << ' ' << "/           saveas  ->  fileName (.txt)        /\n";
	std::cout << std::setw(30) << ' ' << "/           edit    ->  row col string         /\n";
	std::cout << std::setw(30) << ' ' << "/           print                              /\n";
	std::cout << std::setw(30) << ' ' << "/           exit                               /\n";
	std::cout << std::setw(30) << ' ' << "/==============================================/\n";

	std::cout << std::endl;
}

bool Engine::isValidFileFormat(std::string str) {
	int len = str.length();
	if (str[len - 4] == '.' && str[len - 3] == 't' &&
		str[len - 2] == 'x' && str[len - 1] == 't') {
		return true;
	}
	return false;
}

void Engine::run() {
	printCommandList();

	Commands cmds;

	char command[MAX_LENGTH_OF_COMMAND] = { '\0' };

	while (true) {
		std::cout << std::endl;
		std::cout << "Enter a command: \n" << "> ";
		std::cin >> command;

		strcpy_s(command, MAX_LENGTH_OF_COMMAND, toSmallLetters(command));
		
		if (!strcmp(command, "exit")) {
			cmds.exit();
			return;
		}
		runCommand(command, cmds);

		command[0] = '\0';
	}
}

void Engine::runCommand(const char* command, Commands& cmds) {
	if (!strcmp(command, "open")) {
		runOpen(cmds);
	}
	else if (!strcmp(command, "close")) {
		cmds.close();
	}
	else if (!strcmp(command, "save")) {
		cmds.save();
	}
	else if (!strcmp(command, "saveas")) {
		runSaveAs(cmds);
	}
	else if (!strcmp(command, "edit")) {
		runEdit(cmds);
	}
	else if (!strcmp(command, "print")) {
		cmds.print();
	}
	else {
		std::cerr << "Invalid command !" << std::endl;
	}
}

void Engine::runOpen(Commands& cmds) {
	std::string fileName;

	std::cin >> fileName;
	if (isValidFileFormat(fileName)) {
		cmds.open(fileName);
	}
	else {
		std::cout << "Invalid file format !" << std::endl;
	}
}

void Engine::runSaveAs(Commands& cmds) {
	std::string fileName;

	std::cin >> fileName;
	if (isValidFileFormat(fileName)) {
		cmds.saveAs(fileName);
	}
	else {
		std::cout << "Invalid file format !" << std::endl;
	}
}

void Engine::runEdit(Commands& cmds) {
	int row, col;
	std::string data;

	std::cin >> row >> col;
	std::cin >> data;
	cmds.edit(row, col, data);
}

const char* Engine::toSmallLetters(const char* str) {
	char resultStr[MAX_LENGTH_OF_COMMAND];
	strcpy_s(resultStr, MAX_LENGTH_OF_COMMAND, str);
	for (int i = 0; i < MAX_LENGTH_OF_COMMAND; i++) {
		if (isCapitalLetter(str[i])) {
			resultStr[i] = resultStr[i] - 'A' + 'a';
		}
	}
	return resultStr;
}

bool Engine::isCapitalLetter(char c) {
	return 'A' <= c && c <= 'Z';
}