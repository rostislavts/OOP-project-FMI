#ifndef __GLOBALFUNCTIONS__H
#define __GLOBALFUNCTIONS__H

//====================================================//
//                           						  //
//	 BOOLEAN FUNCTIONS, THAT WE ARE GOING TO USE	  //	
//	 IN DIFFERENT CLASSES, THAT ARE NOT CONNECTED!    //	
//                           						  //
//====================================================//

bool isSign(char c);
bool isDigit(char c);
bool isDot(char c);
bool isInteger(const char* str);
bool isDouble(const char* str);
bool isString(const char* str);
bool isValidFormulaOperation(char c);
bool isReference(const char* operand);
bool isValidOperand(const char* operand);
bool isFormula(const char* str);
int getIndexOfOperation(const char* str);
bool createAndCheckOperand(const char* str, int indexFrom, int indexTo);


//=======================//
//						 //
//   LENGTH FUNCTIONS    //
//						 //
//=======================//

int getLength(int x);
int getLength(double x);

#endif