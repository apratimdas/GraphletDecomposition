
#ifndef GRAPHPARSER_H
#define GRAPHPARSER_H

#include "graphletHeaders.h"

namespace graphlet
{
class Parser
{
	enum Formats {
		Pajek,
		JSON,
		XML,
		CSV,
		Regex
	};

	string mFilename;
	Formats mFormat;

public:

	Parser() {};
	Parser(const string& filename, Formats format) : mFilename(filename), mFormat(format) {}

};
	
}


#endif //GRAPHPARSER_H