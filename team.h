#include "include.h"
class team{
private:
	uint32_t id;
	string name;
public:
	team();
	team(uint32_t,string);
	uint32_t getID();
	string getName();
};
