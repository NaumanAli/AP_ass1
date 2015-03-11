#include "include.h"
#include "team.h"
#include "csvParser.h"
class teamManager{
private:
	map <string, team> teams;
	vector <team> teamNames;
	csvParser *parser;
public:
	teamManager();
	void addTeam(team);
	uint32_t getID(string);
	string getName(uint32_t);
	void populateAll();
	map <string, team> getTeams();

};
