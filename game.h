#include "include.h"
class game{
private:
	char season;
	uint32_t daynum;
	uint32_t winTeamID;
	uint32_t winTeamScore;
	uint32_t losTeamID;
	uint32_t losTeamScore;
public:
	game(char,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t);
	char getSeason();
	uint32_t getDaynum();
	uint32_t getWinTeamID();
	uint32_t getWinTeamScore();
	uint32_t getLosTeamID();
	uint32_t getLosTeamScore();
};
