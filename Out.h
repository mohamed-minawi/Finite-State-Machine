#ifndef OUT_H
#define OUT_H

#include "Action.h"
#include <iostream>

class Out :	public Action
{
public:

	// Constructor
	Out() {
		actioname = "Out";
	}

	// Destructor
	~Out(){
	}

	// Initializa the string with the variable name or string to output
	void initialize(std::string out)
	{
		currentstring = out;
		stringb = true;
	}
	void initialize(int out)
	{
		currentint = out;
		stringb = false;
	}

	// Print the required thing
	void execute(Variables & x) 
	{
		if (stringb)
			std::cout << currentstring << std::endl;
		else {
			cout << x.retrievevalue(currentstring) << std::endl;
		}
	}

	// Return the Action Name
	string returname()
	{
		return actioname;
	};

	// Not used but declared for abstract inheritance
	void execute(std::string  &, Transition&) {  }					 
	void execute() {}												

};

#endif