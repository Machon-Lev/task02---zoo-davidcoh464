#include "Monkey.h"

void Monkey::setRandStep()
{
	bool direction = rand() % 2 == 0;
	int sign = rand() % 2 == 0 ? 1 : -1;
	int num_step = rand() % 2 == 0 ? 1 : 2;
	_next_step.row = (direction) * (sign * num_step);
	_next_step.col = (!direction) * (sign * num_step);
}

void Monkey::setLocation()
{
	_loc += _next_step;
	if (++_counter == 5)
	{
		_counter = 0;
		setRandStep();
	}
}

Monkey::Monkey(const string& name, const Location& loc)
	:Animal(name, loc), _counter(0)
{
	setRandStep();
}

void Monkey::printDetails() const
{
	cout << _name << "-" << "Monkey " << _loc;
}

char Monkey::getInitial() const
{
	return 'M';
}

void Monkey::stop()
{
	_isStop = true;
}
