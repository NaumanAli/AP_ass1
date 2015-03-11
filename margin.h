#include "include.h"
class margin{
private:
	int totalPointsScored;
	int totalPointsAllowed;
	int totalGames;
public:
	margin();
	double getMargin();
	void update(uint32_t,uint32_t);
};
