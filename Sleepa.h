#ifndef SLEEPA_H
#define SLEEPA_H

#include "Action.h"
#include <iostream>
#include <Windows.h>

class Sleepa : 	public Action
{
public:

	// Constructor
	Sleepa()
	{
		actioname = "Sleep";
	}

	// Destructor
	~Sleepa() {

	}

	// Initialize the int with the sleep time
	void initialize(int out)
	{
		currentint = out;
	}

	// Pause the program
	void execute()
	{
		Sleep(currentint*1000);
	}

	// Return Action Name 
	string returname()
	{
		return actioname;
	};

	// Not used but declared for abstract inheritance 
	void execute(std::string  &, Transition&) { }				
	void execute(Variables &) {  }								
	void initialize(std::string) {}	

};

#endif