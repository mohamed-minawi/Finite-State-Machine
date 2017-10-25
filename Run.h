#ifndef RUN_H
#define RUN_H

#include "FSM.h"

class Run : public Action
{
public:

	// Constructor
	Run()	{
		actioname = "Run";
	}

	// Destructor
	~Run() {

	}

	// Initialize the string with the FSM name
	void initialize(std::string src)
	{
		currentstring = src;
		if(currentstring.find(',')!=string::npos)
			currentstring.erase(currentstring.length() - 1);
	}

	// Return the Action Name
	string returname()
	{
		return actioname;
	};

	// Execute the new FSM
	void execute()
	{
		FSM x;
		x.loadFSM(currentstring);
		x.runFSM();
	}

	// Not used but declared for abstract inheritance 
	void execute(std::string  &, Transition&) {  }			
	void execute(Variables &) {  }							
	void initialize(int)
	{

	}									
	
};

#endif