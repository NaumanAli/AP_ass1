//class winPer
#include "winPer.h"
winPer::winPer(){
	totalWins=0;
	totalGames=0;
}

winPer::winPer(int wins,int games){
	totalWins=wins;
	totalGames=games;
}
int winPer::getWins(){
	return totalWins;
}
int winPer::getGames(){
	return totalGames;
}
double winPer::getPer(){
	return (double)((double)totalWins/(double)totalGames);
}
void winPer::gameWon(){
	totalWins++;
	totalGames++;
}
void winPer::gameLost(){
	totalGames++;
}