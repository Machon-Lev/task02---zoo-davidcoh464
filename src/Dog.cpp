#include "Dog.h"

void Dog::setLocation()
{
	loc += next_step;
	int sign = next_step.col < 0 ? 1 : -1;
	next_step.col = abs(next_step.col) == 1 ? sign * 3 : sign * 1;
}

void Dog::stop()
{
	if (!isStop)
	{
		isStop = true;
		next_step.col = rand() % 2 == 0 ? 3 : -3;
	}
}
