#ifndef WAIT_H
#define WAIT_H

#include "Action.h"

class Wait :public Action
{
public:

	// Constructor
	Wait() {
		actioname = "Wait";
	}

	// Destructor
	~Wait() {

	}

	// Execute the Wait command
	void execute(std::string  & current, Transition& trans)
	{
		bool validate = true;
		string x;
		while (validate)
		{
			cin >> x;														// user inputs the transition number
			int y = stoi(x);
			validate = !trans.checktransitions(current, y, current);		// validate the transition number
		}
	}

	// Return Action Name
	string returname()
	{
		return actioname;
	};
	
	// Not used but declared for abstract inheritance 
	void execute() {}							
	void execute(Variables &) {  }				
	void initialize(int) {}						
	void initialize(std::string) {}				
};

#endif