#include "FSM.h"
using namespace std;
#include<iostream>

// Constructor
FSM::FSM()
{
	FSMname = "";
}

// Copy Constructor
FSM::FSM(const FSM& other): trans(other.trans), stat(other.stat), var(other.var), FSMname(other.FSMname)
{

}

// Load the FSM from the file
void FSM::loadFSM(string NameofFSM)
{
	FileReader::loadfilefromsource(stat, trans, var, NameofFSM, FSMname, names);
}

// Run the FSM
void FSM::runFSM()
{
	if (FSMname == "")							// Validate that the program was loaded
		throw string("FSM not loaded from any file");
	string currentstate = "a";
	int indexi = int(currentstate[0]) - int('a');	// begin the program with state A

	stringstream usablestream;						// String Stream is used to extract the information like a stream with insertion operator
	
	vector<Action*> hi;
	hi = stat.retrievestateactions(indexi);
	bool endbool = true;
	while (endbool)
	{
		for (int i = 0; i < hi.size(); i++)
		{
			if (hi[i]->returname() == "Out")
				hi[i]->execute(var);
			else if (hi[i]->returname() == "Sleep")
				hi[i]->execute();
			else if (hi[i]->returname() == "Equation")
				hi[i]->execute(var);
			else if (hi[i]->returname() == "Wait")
				hi[i]->execute(currentstate, trans);
			else if (hi[i]->returname() == "Run")
				hi[i]->execute();
			else if (hi[i]->returname() == "End")
				endbool = false;
		}
		int indexi = int(currentstate[0]) - int('a');
		hi = stat.retrievestateactions(indexi);
	}
}

// Destructor
FSM::~FSM()
{
}

vector<string> FSM::names;