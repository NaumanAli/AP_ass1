//class csvParser
#include "csvParser.h"
csvParser::csvParser(string str){
	myFile.open(str.c_str());
}

vector<string> csvParser::getValues(){
	vector<string> result;
    string line;
    getline(myFile,line);
    stringstream lineStream(line);
    string cell;
    while(getline(lineStream,cell,','))
        result.push_back(cell);    
    return result;
}

uint32_t csvParser::toint(string x){
	return atoi(x.c_str());
}
char csvParser::tochar(string x){
	return (char)x[0];
}
