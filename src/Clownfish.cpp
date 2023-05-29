#include"Clownfish.h"

void Clownfish::setRandStep()
{
	int val = rand();
	if (val % 3 == 0) // horizntal
	{
		_next_step.col = rand() % 2 == 0 ? 1 : -1;
	}
	else if (val % 3 == 1) // vertical
	{
		_next_step.row = rand() % 2 == 0 ? 1 : -1;
	}
	else // diagonal
	{
		_next_step.row = _next_step.col = rand() % 2 == 0 ? 1 : -1;
	}
}

void Clownfish::setLocation()
{
	_loc += _next_step;
}

Clownfish::Clownfish(const string& name, const Location& loc)
	: Animal(name, loc)
{
	setRandStep();
}

void Clownfish::printDetails() const
{
	cout << _name << "-" << "Clownfish " << _loc;
}

char Clownfish::getInitial() const
{
	return 'C';
}

void Clownfish::stop()
{
	if (!_isStop)
	{
		_isStop = true;
		setRandStep();
	}
}
