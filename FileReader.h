#ifndef FILE_READER_H
#define FILE_READER_H

#include "State.h"
#include "Transition.h"
#include "Variables.h"
#include <sstream>

using namespace std;

class FileReader
{
public:
	static void loadfilefromsource(State& statevar, Transition& transitionvar, Variables& variablevar, std::string source, string & FSMname, vector<string> &);
};

#endif