//class team
#include "team.h"
team::team(){
}
team::team(uint32_t id,string name){
	this->id=id;
	this->name=name;
}
uint32_t team::getID(){
	return id;
}
string team::getName(){
	return name;
}
