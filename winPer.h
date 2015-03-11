#include "include.h"
class winPer{
private:
	int totalWins;
	int totalGames;
public:
	winPer();
	winPer(int,int);
	int getWins();
	int getGames();
	double getPer();
	void gameWon();
	void gameLost();
};
