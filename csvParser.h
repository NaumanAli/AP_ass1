#include "include.h"
class csvParser{
private:
	ifstream myFile;
public:
	csvParser(string);
 	vector<string> getValues();
 	uint32_t toint(string);
 	char tochar(string);
};
