#ifndef TRANSITION_H
#define TRANSITION_H

#include <vector>
#include <string>

class Transition
{
public:
	// Contstructor
	Transition()
	{
		
	}

	// Copy Constructor
	Transition(const Transition & other) :current(other.current), next(other.next), transitionnumber(other.transitionnumber)
	{

	}

	// Destructor
	~Transition()
	{
		current.clear();
		next.clear();
		transitionnumber.clear();
	}

	// Push the transitions into the transition vectors
	void push(std::string a, std::string b, int c)
	{
		current.push_back(a);
		next.push_back(b);
		transitionnumber.push_back(c);
	}

	// Check with a transition takes place or not and returns new state
	bool checktransitions(std::string a, int b, std::string & c)
	{
		for (int i = 0; i < current.size(); i++)
			if (current[i] == a && transitionnumber[i] == b)
			{
				c = next[i];
				return true;
			}
				return false;
	}

	// Check whether a transition takes place
	bool checktransitions(std::string a, int b)
	{
		for (int i = 0; i < current.size(); i++)
			if (current[i] == a && transitionnumber[i] == b)
				return true;
		return false;
	}

private:
	std::vector<std::string> current;
	std::vector<std::string> next;
	std::vector<int> transitionnumber;

};

#endif