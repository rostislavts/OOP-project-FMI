#ifndef __FORMULA__H
#define __FORMULA__H

class Formula { 
public:
	Formula();
	Formula(const char* leftOperand, const char* rightOperand, char operation);
	~Formula();
	Formula(Formula const& other);
	Formula& operator=(Formula const& other);

	void setLeftOperand(const char* leftOperand);
	void setRightOperand(const char* rightOperand);
	void setOperation(char op);

	const char* getLeftOperand() const  { return this->leftOperand; }
	const char* getRightOperand() const { return this->rightOperand; }
	char getOperation() const 			{ return this->operation; }

private: // methods
	void doCopy(Formula const& otherF);
	void doDelete();

private:
	char* leftOperand;
	char* rightOperand; 
	char operation;
};

#endif