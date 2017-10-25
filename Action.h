#ifndef ACTION_H
#define ACTION_H

#include <string>
#include "Transition.h"
#include "Variables.h"
class Action
{
public:
	Action() {

	}
	~Action() {

	}
	virtual void execute() = 0;
	virtual void execute(std::string&,Transition&) = 0;
	virtual void execute(Variables &) = 0;
	virtual void initialize(int) = 0;
	virtual void initialize(std::string) = 0;
	virtual std::string returname() = 0;

protected:
	int currentint;
	std::string currentstring, actioname;
	bool stringb;
};

#endif