#ifndef EQUATION_H
#define EQUATION_H

#include "Action.h"

class Equation :public Action
{
public:

	// Constructor
	Equation(){
		actioname = "Equation";
	}

	// Destructor
	~Equation(){}

	// Initialize the equation
	void initialize(std::string x) {
		currentstring = x;
	}

	// Exectue the equation
	void execute(Variables & x)
	{  
		string one = currentstring.substr(0, currentstring.find('='));
		string two = currentstring.substr(currentstring.find('=') + 1, currentstring.find('+') - currentstring.find('=') - 1);		// Extract the three paramters of the equation
		string three = currentstring.substr(currentstring.find('+') + 1, currentstring.length() - 2 - currentstring.find('+'));
		
		bool twobool = false, threebool = false;
		int twoint, threeint;
		try
		{
			twoint = stoi(two);
		}
		catch (invalid_argument & e)
		{
			twobool = true;
		}

		try
		{
			threeint = stoi(three);
		}
		catch (invalid_argument & e)
		{
			threebool = true;
		}
		if (!x.checkvariablename(one))
			throw string("Variable in equation doesn't exist First");		// validate the existance of the first parameter
		if (twobool)
		{
			if (!x.checkvariablename(two))										// validate the existance of the second parameter
				throw string("Variable in equation doesn't exist Second");
		}
		if (threebool)
		{
			if (!x.checkvariablename(three))										// validate the existance of the third parameter
				throw string("Variable in equation doesn't exist Third");
		}

		if (twobool == false && threebool == false)
			x.updatevalue(one,twoint + threeint);
		else if (twobool == true && threebool == false)						// Execute the equations
			x.updatevalue(one, x.retrievevalue(two) + threeint);
		else if (twobool == false && threebool == true)
			x.updatevalue(one, twoint + x.retrievevalue(three));
		else
			x.updatevalue(one, x.retrievevalue(two) + x.retrievevalue(three));
	
	}

	// Return the Action Name
	string returname()
	{
		return actioname;
	};
	
	// Not used but declared for abstract inheritance 
	void execute() {}								
	void execute(std::string  &, Transition&) {  }	
	void initialize(int) {}	

};

#endif