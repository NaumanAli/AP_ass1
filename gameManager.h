#include "include.h"
#include "game.h"
#include "margin.h"
#include "winPer.h"
#include "seasonManager.h"
class gameManager{
private:
	map <uint32_t,margin> margins;	
	vector <game> games;
	csvParser *parser;
	map <uint32_t,winPer> winPers;
	map <uint32_t,double> RPI;		
public:
	gameManager();
	void populateWinPer();
	winPer getOppWinPer(uint32_t);
	winPer getOppOppWinPer(uint32_t);
	uint32_t getMaxWinPer();
	void populateByTeamAndSeason(uint32_t,char);
	void populateByTeam(uint32_t);
	void populateBySeason(char);
	void populateAll();
	void addGame(game);
	string getRecord(uint32_t);
	vector<string> getGames(uint32_t,teamManager*);
	uint32_t getNumOfLosses(uint32_t);
	uint32_t getLargestAvgMargin();
	uint32_t getHighestRPI(teamManager* tm);
};
