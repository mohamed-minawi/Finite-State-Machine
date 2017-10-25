#include "FileReader.h"

#include "End.h"
#include "Out.h"
#include "Run.h"
#include "Sleepa.h"
#include "Wait.h"
#include "Equation.h"

#include <string>
#include <fstream>
#include <vector>
using namespace std;

// Loads information from file to the FSM Variables
void FileReader::loadfilefromsource(State& statevar, Transition& transitionvar, Variables& variablevar, std::string source, string & FSMname, vector<string> & names)
{
	string tempname;
	if (source.find(".fsm") == string::npos)
		tempname = source + ".fsm";				// Validate the name of the file
	else tempname = source;

	ifstream input(tempname);						// Open the file
	string temp, info;

	if (!input.fail())
	{
		getline(input, temp);
		while (!input.eof())
		{
			info = info + " " + temp;				// Copy the file content line by line into a string
			getline(input, temp);
		}
		input.close();

		stringstream fakeinput(info);
		bool varbool, statbool, transbool;

		fakeinput >> temp;
		if (temp != "FSM")
			throw string("Invalid FSM File");		// Validate the FSM file content

		fakeinput >> FSMname >> temp;

		for (int i = 0; i < names.size(); i++)
			if (names[i] == FSMname)
				throw string("Invalid FSM, Cannot call previous FSM");

		names.push_back(FSMname);

		if (temp == "VAR")
			varbool = true, statbool = transbool = false;
		else if (temp == "States:")					// Validate the FSM file content and see whether VAR exists or not
			statbool = true, varbool = transbool = false;
		else throw string("Invalid FSM File");

		while (varbool)								// Input the variables into the map structure
		{
			fakeinput >> temp;
			if (temp == "States:")
				statbool = true, varbool = transbool = false;			// stop entering variables when the States word appears
			else if (temp[temp.length() - 1] == ',')
				temp.erase(temp.length() - 1), variablevar.inputvarname(temp);
			else variablevar.inputvarname(temp);
		}

		fakeinput >> temp;
		int t = 0;
		char current;
		while (statbool)							// Input the states into the states vector
		{
			if (temp == "Transitions:")				// stop inputting the states when the word Transition appears
				transbool = true, statbool = false;
			else if (temp.find(":") != string::npos && temp.size() == 2)
			{
				if (temp[0] != char(int('a') + t))	// Validate that the states are in proper alphabetical order
					throw string("States don't have the proper alphabetical order");

				current = temp[0];
				bool tempbool = true;
				statevar.pushstatename(temp);			// Push state into state name to use it to validate the transitions

				while (tempbool)					// Input the actions into the state vector
				{
					fakeinput >> temp;
					if (temp == "wait")				
					{
						Action * other = new Wait;
						statevar.pushaction(int(current) - int('a'), other);
						tempbool = false;
					}
					else if (temp == "end")
					{
						Action * other = new End;
						statevar.pushaction(int(current) - int('a'), other);
						tempbool = false;

					}
					else if (temp == "out")
					{
						Action* other = new Out;
						fakeinput >> temp;
						if (temp.find('"') != string::npos)
						{
							string tempother = temp;
							getline(fakeinput, temp, ',');
							tempother = tempother + temp;
							tempother.erase(0, 1);
							tempother.erase(tempother.length() - 1);
							other->initialize(tempother);
						}
						else {
							int tempother = 0;
							temp.erase(temp.length() - 1);
							if (variablevar.checkvariablename(temp))
								other->initialize(temp), other->initialize(2);
							else throw string("Invalide Variable to display");
						}

						statevar.pushaction(int(current) - int('a'), other);
					}
					else if (temp == "sleep")
					{
						Action* other = new Sleepa;
						fakeinput >> temp;
						other->initialize(stoi(temp));
						statevar.pushaction(int(current) - int('a'), other);
					}
					else if (temp == "run")
					{
						Action* other = new Run;
						fakeinput >> temp;
						other->initialize(temp);
						statevar.pushaction(int(current) - int('a'), other);
					}
					else if(temp.find('=')!=string::npos)
					{
						Action* other = new Equation;
						other->initialize(temp);
						statevar.pushaction(int(current) - int('a'), other);
					}

				}
			}
			else throw string("Invalid FSM File");

			fakeinput >> temp;
			t++;
		}
		string first, second;
		int third;

		while (!fakeinput.eof())					// input the transitions
		{
			if (!statevar.checkstatename(temp))					// validate the existence of the state
				throw string("Invalid State Transitions current");
			if(temp.find(',')!=string::npos)
				temp.erase(temp.length() - 1);
			first = temp;

			fakeinput >> temp;
			if (temp[0] == ',')
				fakeinput >> temp;
			if (!statevar.checkstatename(temp))
				throw string("Invalid State Transitions next");
			if (temp.find(',') != string::npos)
				temp.erase(temp.length() - 1);
			second = temp;

			
			fakeinput >> temp;
			if (temp[0] == ',')
				fakeinput >> temp;
			third = stoi(temp);								// validate that the transition between states is a number

			if (transitionvar.checktransitions(first, third))
				throw string("Invalid Transitions");
			transitionvar.push(first, second, third);		// push each transition into transition vector.
			
			fakeinput >> temp;
		}

	}
	else throw string("File failed to open");

}
