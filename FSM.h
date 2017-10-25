#pragma once
#include <string>

#include "FileReader.h"
#include <vector>
using namespace std;

class FSM
{
public:
	FSM();
	FSM(const FSM &);
	~FSM();

	void loadFSM(string name);
	void runFSM();
	
private:
	Transition trans;
	State stat;
	Variables var;
	string FSMname;
	static vector<string> names;
};

