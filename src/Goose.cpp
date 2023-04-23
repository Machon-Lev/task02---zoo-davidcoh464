#include "Goose.h"

void Goose::setLocation()
{
	loc += next_step;
	if (loc.col == COLUMNS - 1 || loc.col == 0)
		next_step.col = (-1) * next_step.col;
	next_step.row = (-1) * next_step.row;
}

void Goose::stop()
{
	if (!isStop)
	{
		isStop = true;
		next_step.col = rand() % 2 == 0 ? 1 : -1;
	}
}
