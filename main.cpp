#include "include.h"
#include "gameManager.h"
void printVector(vector<string> x){
	for(int i=0;i<x.size();i++)
		cout<<x[i]<<endl;
}


int main(int argc, char *argv[]){
	seasonManager SM;
	gameManager GM;
	teamManager TM;
	string str(argv[1]);
	if(str=="rpiChampion"){
		GM.populateBySeason(SM.getChar(argv[2]));
		GM.populateWinPer();
		cout<<TM.getName(GM.getHighestRPI(&TM));
	}
	else if(str=="list"){
		GM.populateByTeamAndSeason(TM.getID(argv[3]),SM.getChar(argv[2]));
		printVector(GM.getGames(TM.getID(argv[3]),&TM));
	}
	else if(str=="finalRecord"){
		GM.populateByTeamAndSeason(TM.getID(argv[3]),SM.getChar(argv[2]));;
		cout<<GM.getRecord(TM.getID(argv[3]));
	}
	else if(str=="bestWinPercentage"){
		GM.populateBySeason(SM.getChar(argv[2]));
		GM.populateWinPer();
		cout<<TM.getName(GM.getMaxWinPer());
	}
	else if(str=="largestMargin"){
		GM.populateBySeason(SM.getChar(argv[2]));;
		cout<<TM.getName(GM.getLargestAvgMargin());
	}

}