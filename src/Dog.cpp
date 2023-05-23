#include "Dog.h"

void Dog::setLocation()
{
	_loc += _next_step;
	int sign = _next_step.col < 0 ? 1 : -1;
	_next_step.col = abs(_next_step.col) == 1 ? sign * 3 : sign * 1;
}

Dog::Dog(const string& name, const Location& loc)
	:Animal(name, loc)
{
	_next_step.col = rand() % 2 == 0 ? 3 : -3;
	_next_step.row = 0;
}

void Dog::printDetails() const
{
	cout << _name << "-" << "Dog " << _loc;
}

char Dog::getInitial() const
{
	return 'D';
}

void Dog::stop()
{
	if (!_isStop)
	{
		_isStop = true;
		_next_step.col = rand() % 2 == 0 ? 3 : -3;
	}
}
