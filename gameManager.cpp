//class gameManager
#include "gameManager.h"
gameManager::gameManager(){
	parser=new csvParser("regular_tourney_combined_results.csv");
}
void gameManager::populateByTeam(uint32_t id){
	
	vector <string> values;
	while(((values=parser->getValues()).size())!=0)	{	
		if((parser->toint(values[2])==id||parser->toint(values[4])==id)){
			game gameX(parser->tochar(values[0]),parser->toint(values[1]),parser->toint(values[2]),parser->toint(values[3]),parser->toint(values[4]),parser->toint(values[5]));
			addGame(gameX);
		}	
	}
}

void gameManager::populateByTeamAndSeason(uint32_t id,char Season){
	
	vector <string> values;
	while(((values=parser->getValues()).size())!=0)	{	
		if(parser->tochar(values[0])==Season &&(parser->toint(values[2])==id||parser->toint(values[4])==id)){
			game gameX(parser->tochar(values[0]),parser->toint(values[1]),parser->toint(values[2]),parser->toint(values[3]),parser->toint(values[4]),parser->toint(values[5]));
			addGame(gameX);
		}	
	}
}
void gameManager::populateBySeason(char Season){
	
	vector <string> values;
	while(((values=parser->getValues()).size())!=0)	{	
		if(parser->tochar(values[0])==Season){
			game gameX(parser->tochar(values[0]),parser->toint(values[1]),parser->toint(values[2]),parser->toint(values[3]),parser->toint(values[4]),parser->toint(values[5]));
			addGame(gameX);
		}	
	}
}
void gameManager::populateAll(){	
	vector <string> values;
	while(((values=parser->getValues()).size())!=0)	{	
			game gameX(parser->tochar(values[0]),parser->toint(values[1]),parser->toint(values[2]),parser->toint(values[3]),parser->toint(values[4]),parser->toint(values[5]));
			addGame(gameX);		
	}
}

void gameManager::addGame(game gameX){
	games.push_back(gameX);
}

uint32_t gameManager::getLargestAvgMargin(){
	double mar=0.0;
	uint32_t max;	
	map <uint32_t,margin>::iterator it;
	for(int i=0;i<games.size();i++){
		it=margins.find(games[i].getWinTeamID());
		if(it==margins.end()){
			margin x;
			x.update(games[i].getWinTeamScore(),games[i].getLosTeamScore());			
			margins[games[i].getWinTeamID()]=x;
		}
		else{
			margin x=it->second;
			x.update(games[i].getWinTeamScore(),games[i].getLosTeamScore());
			it->second=x;
		}
		it=margins.find(games[i].getLosTeamID());
		if(it==margins.end()){	
			margin x;		
			x.update(games[i].getLosTeamScore(),games[i].getWinTeamScore());	
			margins[games[i].getLosTeamID()]=x;
		}
		else{
			margin x=it->second;
			x.update(games[i].getLosTeamScore(),games[i].getWinTeamScore());
			it->second=x;
		}

	}
	for(it=margins.begin();it != margins.end(); it++){
		if(it->second.getMargin()>mar){
					mar=it->second.getMargin();
					max=it->first;
		}
	}

	return max;

}

string gameManager::getRecord(uint32_t id){
	int wins=0,losses=0;
	string result;
	stringstream sstm;
	for(int i=0;i<games.size();i++){
		if(games[i].getWinTeamID()==id)
			wins++;
		else if(games[i].getLosTeamID()==id)
			losses++;
	}
	sstm << wins <<"-" << losses;
	result = sstm.str();
	return result;

}
vector<string> gameManager::getGames(uint32_t id,teamManager* tm){
	char res;
	vector<string> results;
	uint32_t pointsScored,pointsAllowed;
	string result,teamName;		
	for(int i=0;i<games.size();i++){
		stringstream sstm;
		if(games[i].getWinTeamID()==id){
			teamName=tm->getName(games[i].getLosTeamID());
			res='W';
			pointsScored=games[i].getWinTeamScore();
			pointsAllowed=games[i].getLosTeamScore();
		}
		else if(games[i].getLosTeamID()==id){
			teamName=tm->getName(games[i].getWinTeamID());
			res='L';
			pointsScored=games[i].getLosTeamScore();
			pointsAllowed=games[i].getWinTeamScore();
		}
		sstm << res <<" " <<teamName << " " << pointsScored <<"-" << pointsAllowed;
		result = sstm.str();
		results.push_back(result);
	}
	return results;

}

void gameManager::populateWinPer(){
	map <uint32_t,winPer>::iterator it;
	for(int i=0;i<games.size();i++){
		it=winPers.find(games[i].getWinTeamID());
		if(it==winPers.end()){
			winPer x;
			x.gameWon();			
			winPers[games[i].getWinTeamID()]=x;
		}
		else{
			winPer x=it->second;
			x.gameWon();
			it->second=x;
		}
		it=winPers.find(games[i].getLosTeamID());
		if(it==winPers.end()){	
			winPer x;		
			x.gameLost();	
			winPers[games[i].getLosTeamID()]=x;
		}
		else{
			winPer x=it->second;
			x.gameLost();
			it->second=x;
		}

	}	
}

uint32_t gameManager::getMaxWinPer(){
	uint32_t max;
	double maxWinPer=0.0;
	map <uint32_t,winPer>::iterator it;
	for(it=winPers.begin();it != winPers.end(); it++){
		if(it->second.getPer()>maxWinPer){
					maxWinPer=it->second.getPer();
					max=it->first;
		}
	}
	return max;

}
winPer gameManager::getOppWinPer(uint32_t id){
	int totalWins=0,totalGames=0;
	for(int i=0;i<games.size();i++){
		if(games[i].getWinTeamID()==id){
			totalWins+=winPers[games[i].getLosTeamID()].getWins();
			totalGames+=winPers[games[i].getLosTeamID()].getGames();
		}
		else if (games[i].getLosTeamID()==id){
			totalWins+=winPers[games[i].getWinTeamID()].getWins();
			totalGames+=winPers[games[i].getWinTeamID()].getGames();			
			
		}
	}
	winPer x(totalWins,totalGames);
	return x;


}

winPer gameManager::getOppOppWinPer(uint32_t id){
	int totalWins=0,totalGames=0;
	winPer x;
	for(int i=0;i<games.size();i++){
		if(games[i].getWinTeamID()==id){
			x=getOppWinPer(games[i].getLosTeamID());
			totalWins+=x.getWins();
			totalGames+=x.getGames();
		}
		else if(games[i].getLosTeamID()==id){
			x=getOppWinPer(games[i].getWinTeamID());
			totalWins+=x.getWins();
			totalGames+=x.getGames();
		}
	}
	winPer y(totalWins,totalGames);
	return y;

	
}

uint32_t gameManager::getHighestRPI(teamManager* tm){
	map <uint32_t,double> RPI;
	winPer oppWinPer,oppOppWinPer;
	double temp,max=0.0;
	uint32_t maxid;
	map <string, team>::iterator it;
	map <string, team> teams = tm->getTeams();
	for(it=teams.begin();it != teams.end(); it++){
		oppWinPer=getOppWinPer(tm->getID(it->first));
		oppOppWinPer=getOppOppWinPer(tm->getID(it->first));
		temp=0.25*winPers[(tm->getID(it->first))].getPer()+0.5*(oppWinPer.getPer())+0.25*(oppOppWinPer.getPer());
		RPI[tm->getID(it->first)]=temp;
		if(temp>max){
					max=temp;
					maxid=tm->getID(it->first);
		}
	}
	return maxid;
		
}
