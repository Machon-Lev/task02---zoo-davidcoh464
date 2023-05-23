#include "Goose.h"

void Goose::setLocation()
{
	_loc += _next_step;
	if (_loc.col == COLUMNS - 1 || _loc.col == 0)
		_next_step.col = (-1) * _next_step.col;
	_next_step.row = (-1) * _next_step.row;
}

Goose::Goose(const string& name, const Location& loc)
	:Animal(name, loc)
{
	_next_step.col = rand() % 2 == 0 ? 1 : -1;
	_next_step.row = 1;
}

void Goose::printDetails() const
{
	cout << _name << "-" << "Goose " << _loc;
}

char Goose::getInitial() const
{
	return 'G';
}

void Goose::stop()
{
	if (!_isStop)
	{
		_isStop = true;
		_next_step.col = rand() % 2 == 0 ? 1 : -1;
	}
}
