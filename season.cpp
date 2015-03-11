#include "season.h"
//class season
season::season(){
}
season::season(char season,string year){
	this->id=season;
	this->year=year;
}
string season::getYear(){
	return year;
}

char season::getChar(){
	return id;
}



