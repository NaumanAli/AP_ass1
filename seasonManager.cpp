//class seasonManager
#include "seasonManager.h"
seasonManager::seasonManager(){
	parser=new csvParser("seasons.csv");
	vector <string> values;
	while(((values=parser->getValues()).size())!=0)	{	
			season seasonX(parser->tochar(values[0]),values[1]);
			addSeason(seasonX);		
	}
}

void seasonManager::populateAll(){	
	vector <string> values;
	while(((values=parser->getValues()).size())!=0)	{	
			season seasonX(parser->tochar(values[0]),values[1]);
			addSeason(seasonX);		
	}
}

void seasonManager::addSeason(season seasonX){
	seasons[seasonX.getChar()]=seasonX;
}

char seasonManager::getChar(string year){
	for (map<char, season>::iterator it =seasons.begin();
it !=seasons.end();it++)
{
	if(it->second.getYear()==year)
		return it->second.getChar();
}
	return -1;
}
string seasonManager::getYear(char id){
		return seasons[id].getYear();
}
