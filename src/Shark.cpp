#include "Shark.h"

void Shark::setRandStep()
{
	int val = rand();
	if (val % 3 == 0) // horizntal
	{
		_next_step.col = rand() % 2 == 0 ? 5 : -5;
	}
	else if (val % 3 == 1) // vertical
	{
		_next_step.row = rand() % 2 == 0 ? 5 : -5;
	}
	else // diagonal
	{
		_next_step.row = _next_step.col = rand() % 2 == 0 ? 5 : -5;
	}
}

void Shark::setLocation()
{
	_loc += _next_step;
}

Shark::Shark(const string& name, const Location& loc)
	: Animal(name, loc)
{
	setRandStep();
}

void Shark::printDetails() const
{
	cout << _name << "-" << "Shark " << _loc;
}

char Shark::getInitial() const
{
	return 'S';
}

void Shark::stop()
{
	if (!_isStop)
	{
		_isStop = true;
		setRandStep();
	}
}
