//class teamManager


#include "teamManager.h"
teamManager::teamManager(){
	parser=new csvParser("teams.csv");
	vector <string> values;
	while(((values=parser->getValues()).size())!=0)	{	
			team teamX(parser->toint(values[0]),values[1]);
			addTeam(teamX);		
	}
}

map <string, team> teamManager::getTeams(){
	return teams;
}
void teamManager::populateAll(){	
	vector <string> values;
	while(((values=parser->getValues()).size())!=0)	{	
			team teamX(parser->toint(values[0]),values[1]);
			addTeam(teamX);		
	}
}

void teamManager::addTeam(team teamX){
	teams[teamX.getName()]=teamX;
	teamNames.push_back(teamX);
}

uint32_t teamManager::getID(string name){
	return teams[name].getID();
}

string teamManager::getName(uint32_t id){
	return teamNames[id-500].getName();
}

