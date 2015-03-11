//class game
#include "game.h"
game::game(char season,uint32_t daynum,uint32_t winTeamID,uint32_t winTeamScore,uint32_t losTeamID,uint32_t losTeamScore){
	this->season=season;
	this->daynum=daynum;
	this->winTeamID=winTeamID;
	this->winTeamScore=winTeamScore;
	this->losTeamID=losTeamID;
	this->losTeamScore=losTeamScore;
}
char game::getSeason(){
	return season;
}
uint32_t game::getDaynum(){
	return daynum;
}
uint32_t game::getWinTeamID(){
	return winTeamID;
}
uint32_t game::getWinTeamScore(){
	return winTeamScore;
}
uint32_t game::getLosTeamID(){
	return losTeamID;
}
uint32_t game::getLosTeamScore(){
	return losTeamScore;
}
