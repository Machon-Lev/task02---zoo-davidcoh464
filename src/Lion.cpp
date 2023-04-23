#include "Lion.h"

void Lion::setLocation()
{
	switch (next_step.col)
	{
	case 2:
		if (loc.col + 2 >= COLUMNS)
		{
			if (loc.col + 2 == COLUMNS)
				loc.col = COLUMNS - 2;
			else
				loc.col = COLUMNS - 3;
			next_step.col = -2;
		}
		else
			loc += next_step;
		break;
	case -2:
		if (loc.col - 2 < 0)
		{
			if (loc.col - 2 == -1)
				loc.col = 1;
			else
				loc.col = 2;
			next_step.col = 2;
		}
		else
			loc += next_step;
		break;
	default:
		break;
	}
}

void Lion::stop()
{
	if (!isStop)
	{
		isStop = true;
		next_step.col = rand() % 2 == 0 ? 2 : -2;
	}
}
