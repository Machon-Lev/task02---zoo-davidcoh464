#include "Lion.h"

void Lion::setLocation()
{
	switch (_next_step.col)
	{
	case 2:
		if (_loc.col + 2 >= COLUMNS)
		{
			if (_loc.col + 2 == COLUMNS)
				_loc.col = COLUMNS - 2;
			else
				_loc.col = COLUMNS - 3;
			_next_step.col = -2;
		}
		else
			_loc += _next_step;
		break;
	case -2:
		if (_loc.col - 2 < 0)
		{
			if (_loc.col - 2 == -1)
				_loc.col = 1;
			else
				_loc.col = 2;
			_next_step.col = 2;
		}
		else
			_loc += _next_step;
		break;
	default:
		break;
	}
}

Lion::Lion(const string& name, const Location& loc)
	:Animal(name, loc)
{
	_next_step.col = rand() % 2 == 0 ? 2 : -2;
	_next_step.row = 0;
}

void Lion::printDetails() const
{
	cout << _name << "-" << "Lion " << _loc;
}

char Lion::getInitial() const
{
	return 'L';
}

void Lion::stop()
{
	if (!_isStop)
	{
		_isStop = true;
		_next_step.col = rand() % 2 == 0 ? 2 : -2;
	}
}
