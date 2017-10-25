#ifndef VARIABLES_H
#define VARIABLES_H

#include <vector>
#include <map>
#include <string>


class Variables
{
public:

	// Default Constructor
	Variables() {

	}

	// Copy Constructor
	Variables(const Variables & other) : variables(other.variables), variablenames(other.variablenames)
	{

	}

	// Destructor
	~Variables() {

	}

	// Check if variable name is available for validation
	bool checkvariablename(std::string a){
		for (int i = 0; i < variablenames.size(); i++)
			if (a == variablenames[i])
				return true;
		return false;
	}

	// Enter variable name into variable vector and map
	void inputvarname(std::string a) {
		variables.insert(std::pair<std::string, int>(a,0));
		variablenames.push_back(a);
	}

	// Update value of the variable
	void updatevalue(std::string a, int b) {
		variables[a] = b;
	}

	// Retrieve the value of the variable
	int retrievevalue(std::string a){
		return variables[a];
	}
	

private:
	std::map<std::string, int> variables;
	std::vector<std::string> variablenames;
};

#endif

