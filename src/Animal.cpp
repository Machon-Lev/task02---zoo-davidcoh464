#include "Animal.h"

Animal::Animal(const string& name, const Location& loc)
	: _name(name), _loc(loc), _isStop(false) {}

void Animal::step()
{
	if (!_isStop)
	{
		setLocation();
	}
}

void Animal::move()
{
	_isStop = false;
}

Location Animal::getLocation() const
{
	return _loc;
}

void Animal::turnHorizontally()
{
	_next_step.col = -_next_step.col;
}

void Animal::turnVertically()
{
	_next_step.row = -_next_step.row;
}

