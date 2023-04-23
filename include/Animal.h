#pragma once
#include "Location.h"

using std::string, std::cout, std::endl;

class Animal 
{
protected:
	string name;
	Location loc, next_step;
	bool isStop;
	virtual void setLocation() = 0;
public:
	Animal(const string& _name, const Location& _loc) : name(_name), loc(_loc), isStop(false){}
	virtual void printDetails()const = 0;
	virtual char getInitial()const = 0;
	virtual void stop() = 0;
	virtual void step();
	void move() { isStop = false; }
	Location getLocation()const { return loc; }
	void turnHorizontally() { next_step.col = - next_step.col; }
	void turnVertically() { next_step.row = - next_step.row; }
};