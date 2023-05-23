#pragma once
#include "Location.h"

using std::string, std::cout, std::endl;

class Animal 
{
protected:
	string _name;
	Location _loc, _next_step;
	bool _isStop;
	virtual void setLocation() = 0;
public:
	Animal(const string& name, const Location& loc);
	virtual void printDetails()const = 0;
	virtual char getInitial()const = 0;
	virtual void stop() = 0;
	virtual void step();
	void move();
	Location getLocation()const;
	void turnHorizontally();
	void turnVertically();
};