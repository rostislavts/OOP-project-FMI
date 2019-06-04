#ifndef __STRINGCELL__H
#define __STRINGCELL__H

#include "Cell.h"

class StringCell : public Cell {
public:
	StringCell();
	StringCell(int indexOfRow, int indexOfCol, const char* data);
	StringCell(StringCell const& otherCell);
	StringCell& operator=(StringCell const& otherCell); 
	~StringCell();

	void setData(const char* data);

	const char* getData() const { return this->data; }

	int getLengthOfData() const;
	double getValue() const;

	StringCell* clone();

	void print(std::ostream& os = std::cout) const;


private: //methods
	void doCopy(StringCell const& otherCell); 
	void doDelete();
	
private:
	char* data;
};

#endif