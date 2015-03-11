#include "include.h"
#include "season.h"
#include"teamManager.h"
class seasonManager{
private:
	csvParser *parser;
	map <char, season> seasons;
public:
	seasonManager();
	void populateAll();
	void addSeason(season);
	string getYear(char);
	char getChar(string);

};
