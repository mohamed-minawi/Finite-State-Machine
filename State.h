#ifndef STATE_H
#define STATE_H

#include <vector>
#include <string>
#include "Action.h"

class State
{
public:

	// Default Constructor
	State()
	{

	}

	// Copy Constructor
	State(const State & other): states(other.states), statenames(other.statenames)
	{

	}

	// Destructor
	~State()
	{

	}

	// Push Action into vector 
	void pushaction(int statenum, Action* action)
	{
		if (statenum < states.size())		// if corresponding row exists, push action automatically
			states[statenum].push_back(action);
		else {								// if row doesn't exist, create a new row and push action
			std::vector<Action*> temp;
			temp.push_back(action);
			states.push_back(temp);
		}
	}

	// rRtrieve the actions of the state
	std::vector<Action*> retrievestateactions(int statesnum)
	{
		return states[statesnum];						
	}

	// Push name of state for validation
	void pushstatename(std::string name)
	{
		if (name.size() == 2)
			name.erase(1);
		statenames.push_back(name);
	}

	// Check if the state is available or not
	bool checkstatename(std::string name)
	{
		for (int i = 0; i < statenames.size(); i++)
			if (name[0] == statenames[i][0])
				return true;
		return false;
	}

private:
	std::vector<std::vector<Action*>> states;
	std::vector<std::string> statenames;
};

#endif