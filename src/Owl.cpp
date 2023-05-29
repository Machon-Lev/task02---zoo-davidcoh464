#include "Owl.h"

void Owl::setLocation()
{
	if (_next_step.col > 0 && (_loc.col == COLUMNS - 1 || _loc.row == ROWS - 1)
		|| _next_step.col < 0 && (_loc.col == 0 || _loc.row == 0))
		_next_step.col = _next_step.row = (-1) * _next_step.col;
	_loc += _next_step;
}

Owl::Owl(const string& name, const Location& loc)
	: Animal(name, loc)
{
	_next_step.col = _next_step.row = rand() % 2 == 0 ? 3 : -3;
}

void Owl::printDetails() const
{
	cout << _name << "-" << "Owl " << _loc;
}

char Owl::getInitial() const
{
	return 'O';
}

void Owl::stop()
{
	if (!_isStop)
	{
		_isStop = true; 
		_next_step.col = _next_step.row = rand() % 2 == 0 ? 3 : -3;
	}
}
