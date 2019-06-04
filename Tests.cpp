#include "Tests.h"

#include <iostream>
#include <typeinfo>
#include <fstream>
#include <string>
#include <stdio.h>


#include "Cell.h"
#include "EmptyCell.h"
#include "IntCell.h"
#include "DoubleCell.h"
#include "StringCell.h"
#include "FormulaCell.h"
#include "Formula.h"
#include "Table.h"

#include "Row.h"

using namespace std;

// ====================================== TESTS =====================================

#include "GlobalFunctions.h"
/*
void intTests() {
	const char* str1 = "2324";
	const char* str2 = "23 24";
	const char* str3 = "+2326";
	const char* str4 = "2+324";
	const char* str5 = "_2324";
	const char* str6 = "2a324";
	const char* str7 = "a2324";
	const char* str8 = "+-2324";
	const char* str9 = "2324+";
	const char* str10 = "-1234";

	if (isInteger(str1)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isInteger(str2)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isInteger(str3)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isInteger(str4)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isInteger(str5)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isInteger(str6)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isInteger(str7)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isInteger(str8)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isInteger(str9)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isInteger(str10)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

}



void doubleTests() {
	const char* str1 = "23.24";
	const char* str2 = "-23.24";
	const char* str3 = "+2.326";
	const char* str4 = ".2324";
	const char* str5 = "+.2324";
	const char* str6 = "2a324";
	const char* str7 = "a2324";
	const char* str8 = "+-232.4";
	const char* str9 = "2324.";
	const char* str10 = "-1234.";
	const char* str11 = "1234";

	if (isDouble(str1)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isDouble(str2)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isDouble(str3)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isDouble(str4)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isDouble(str5)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isDouble(str6)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isDouble(str7)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isDouble(str8)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isDouble(str9)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isDouble(str10)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isDouble(str11)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}


void testFormula() {
	const char* str1 = "=10*R12C52";
	const char* str2 = "=42*123.43";
	const char* str3 = "=R9C5*R1C1";
	const char* str4 = "=15.23-23.41";
	const char* str5 = "=R1C9/12";

	const char* str6 = "=R2.3C2+5";
	const char* str7 = "=10-R123C23C";
	const char* str8 = "=1^r12c1";

	if (isFormula(str1)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isFormula(str2)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isFormula(str3)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isFormula(str4)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isFormula(str5)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isFormula(str6)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isFormula(str7)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isFormula(str8)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

}

void testIsValidOperand() {
	const char* op1 = "R1C9";
	const char* op2 = "10.23";
	const char* op3 = "42";
	const char* op4 = "r12C123";
	const char* op5 = "R1.2C42";
	const char* op6 = "r1c2";

	if (isValidOperand(op1)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isValidOperand(op2)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isValidOperand(op3)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isValidOperand(op4)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isValidOperand(op5)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	if (isValidOperand(op6)) {
		cout << "YES!" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

void testFormulaCell() {
	Formula f("12", "5", '+');
	FormulaCell fc(1, 2, f);

	Cell* pointer = &fc;

	pointer->print();

}

void testPrint() {
	Table t;

	Row r1;

	Cell* i1 = new IntCell(1, 1, 13);
	Cell* i2 = new IntCell(1, 2, 4);

	Cell* d1 = new DoubleCell(0, 0, 12.4);
	Cell* d2 = new DoubleCell(0, 3, -3434.5);

	Cell * s1 = new StringCell(0, 1, "Hello!");
	Cell * s2 = new StringCell(0, 13, "Echo");  // col == 4 problem !!!
	Cell * s3 = new StringCell(0, 0, "Hsd");
	Cell * s4 = new StringCell(2, 5, "123");

	Formula f1("R5C1", "15", '+');
	Formula f2("R0C0", "2", '*');
	Formula f3("10", "0", '/');
	Formula f4("10", "R0C1", '/');
	Formula f5("-123", "12", '+');
	Formula f6("R2C5", "7", '+');

	Cell * fc1 = new FormulaCell(3, 4, f1);
	Cell * fc2 = new FormulaCell(5, 1, f2);
	Cell * fc3 = new FormulaCell(0, 7, f3);
	Cell * fc4 = new FormulaCell(0, 9, f4);
	Cell * fc5 = new FormulaCell(1, 5, f5);
	Cell * fc6 = new FormulaCell(1, 8, f6);

	Cell * ec = new EmptyCell(1, 2);

	//r1.addCell(i2);
	//r1.addCell(fc2);



	//r1.addCell(d2);
	//r1.getRowCells()[1]->print();
	//r1.print();




	t.addCell(i1); // problem !!!
	t.addCell(i2);

	t.addCell(d1);
	t.addCell(d2);
	//t.getRows()[0].getRowCells()[3]->print();
	t.addCell(s1);
	t.addCell(s2); // problem !!!
	//t.addCell(s3);
	t.addCell(s4);
	//cout << t.getRows()[0].getCapacity() << endl;
	t.addCell(fc1);
	t.addCell(fc2);
	t.addCell(fc3);
	t.addCell(fc4);
	t.addCell(fc5);
	t.addCell(fc6);

	t.print();
	cout << endl;
	cout << endl;
	cout << endl;


	cout << "Calculated table : ( I will fix the indexes! Now they start from (0,0) ) " << endl;
	cout << endl;
	//cout << t.calculateFormula(f1) << endl;
	t.calculateFormulas().print(); // check this !!!

	cout << endl;
	cout << endl;
	cout << endl;

	cout << "Edit test: " << endl;
	cout << endl;

	t.edit(0, 0, "alabala");
	t.edit(1, 2, "12.5");
	t.edit(0, 7, "123");
	t.edit(-1, 2, "abc");
	t.edit(0, 0, "=R1C1*2");

	t.print();

	cout << endl;
	cout << endl;
	cout << endl;

	t.calculateFormulas().print();
	cout << endl;


	//cout << d2->getLengthOfData() << endl;
	//cout << fc1->getLengthOfData() << endl;
	//cout << f1.getLeftOperand() << ' ' << strlen(f1.getLeftOperand()) << endl;
	//cout << f1.getRightOperand() << ' ' << strlen(f1.getRightOperand()) << endl;
	//cout << f1.getOperation() << endl;

	//t.getRows()[0].getRowCells()[0]->print();


	//r1.addCell(i1);
	//r1.addCell(i2);
	//r1.print();

	//r1.addCell(d1);
	//r1.addCell(d2);

	//r1.addCell(s1);
	//r1.addCell(s2);


}

void testStreams() {
	Table t;

	Cell* i1 = new IntCell(1, 1, 13);
	Cell* i2 = new IntCell(1, 2, 4);

	Cell* d1 = new DoubleCell(0, 0, 12.4);
	Cell* d2 = new DoubleCell(0, 3, -3434.5);

	Cell * s1 = new StringCell(0, 1, "Hello!");
	Cell * s2 = new StringCell(0, 13, "Echo");  // col == 4 problem !!!
	Cell * s3 = new StringCell(0, 0, "Hsd");
	Cell * s4 = new StringCell(2, 5, "123");

	Formula f1("R5C1", "15", '+');
	Formula f2("R0C0", "2", '*');
	Formula f3("10", "0", '/');
	Formula f4("10", "R0C1", '/');
	Formula f5("-123", "12", '+');
	Formula f6("R2C5", "7", '+');

	Cell * fc1 = new FormulaCell(3, 4, f1);
	Cell * fc2 = new FormulaCell(5, 1, f2);
	Cell * fc3 = new FormulaCell(0, 7, f3);
	Cell * fc4 = new FormulaCell(0, 9, f4);
	Cell * fc5 = new FormulaCell(1, 5, f5);
	Cell * fc6 = new FormulaCell(1, 8, f6);

	Cell * ec = new EmptyCell(1, 2);

	ofstream ofs;
	ofs.open("Table.txt");

	t.addCell(i1); // problem !!!
	t.addCell(i2);

	t.addCell(d1);
	t.addCell(d2);
	//t.getRows()[0].getRowCells()[3]->print();
	t.addCell(s1);
	t.addCell(s2); // problem !!!
	//t.addCell(s3);
	t.addCell(s4);
	//cout << t.getRows()[0].getCapacity() << endl;
	t.addCell(fc1);
	t.addCell(fc2);
	t.addCell(fc3);
	t.addCell(fc4);
	t.addCell(fc5);
	t.addCell(fc6);

	t.print();
	cout << endl;
	cout << endl;
	cout << endl;

	cout << "Calculated table : ( I will fix the indexes! Now they start from (0,0) ) " << endl;
	cout << endl;
	//cout << t.calculateFormula(f1) << endl;
	t.calculateFormulas().print(ofs); // check this !!!

	cout << endl;
	cout << endl;
	cout << endl;

	cout << "Edit test: " << endl;
	cout << endl;

	t.edit(0, 0, "alabala");
	t.edit(1, 2, "12.5");
	t.edit(0, 7, "123");
	t.edit(-1, 2, "abc");
	
	t.print();

	cout << endl;
	cout << endl;
	cout << endl;

	//ofs << endl;
	//ofs << endl;
	//ofs << endl;

	t.calculateFormulas().print();
	cout << endl;

	ofs.close();
}


/*

int alabala() {

ifstream ifs;
ifs.open("text.txt");

if(ifs.fail()) {
	cerr << "Eror opening file!!!" << endl;
	exit(1);
}
int x, y;
ifs >> x >> y;



// Read file until you have reached the end

string item;
int count = 0;

while(!ifs.eof()) {
	ifs >> item;
	if(item == "orange") {
		count++;
	}
}

ifs.close();
// OFSTREAM

ofstream ofs;

ofs.open("text.txt");

ofs << "First number: " << 5 << endl;


ofs.close();
	return 0;
}

int main23() {
	const char* c = "-25256";
	const char* d = "+45643";

	const char* f = "alabala";
	const char* s = "0";
	const char* y = "24.556";
	const char* p = "24.556.732";

	cout << atoi(c) << endl <<  atoi(d) << endl;
	cout << atoi(f) << endl;

	cout << atof(y) << endl << atof(p) << endl;
	return 0;
}

int mainASD() {
	const char* c = "\"alabala\"" ;
	cout << c <<  endl;
	return 0;
}
*/


