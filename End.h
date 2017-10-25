#ifndef END_H
#define END_H

#include "Action.h"

class End :	public Action
{
public:

	// Constructor
	End(){
		actioname = "End";
	}

	// Destructor
	~End() {}

	// Return the Action Name 
	string returname()
	{
		return actioname;
	};

	// Not used but declared for abstract inheritance 
	void execute() {}
	void execute(std::string  &, Transition&) {  }				
	void execute(Variables &) {  }							
	void initialize(int) {}										
	void initialize(std::string) {}							 
};

#endif