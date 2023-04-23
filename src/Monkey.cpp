#include "Monkey.h"

void Monkey::setRandStep()
{
	bool direction = rand() % 2 == 0;
	int sign = rand() % 2 == 0 ? 1 : -1;
	int num_step = rand() % 2 == 0 ? 1 : 2;
	next_step.row = (direction) * (sign * num_step);
	next_step.col = (!direction) * (sign * num_step);
}

void Monkey::setLocation()
{
	loc += next_step;
	if (++counter == 5)
	{
		counter = 0;
		setRandStep();
	}
}

void Monkey::stop()
{
	isStop = true;
}
