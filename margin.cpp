//class margin
#include "margin.h"
margin::margin(){
	totalPointsScored=0;
	totalPointsAllowed=0;
	totalGames=0;
}
double margin::getMargin(){
	return (double)((double)(totalPointsScored-totalPointsAllowed)/(double)totalGames);
}
void margin::update(uint32_t pointsScored,uint32_t pointsAllowed){
	totalPointsAllowed+=pointsAllowed;
	totalPointsScored+=pointsScored;
	totalGames++;
}