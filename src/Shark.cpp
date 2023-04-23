#include "Shark.h"

void Shark::setRandStep()
{
	int val = rand();
	if (val % 3 == 0) // horizntal
	{
		next_step.col = rand() % 2 == 0 ? 5 : -5;
	}
	else if (val % 3 == 1) // vertical
	{
		next_step.row = rand() % 2 == 0 ? 5 : -5;
	}
	else // diagonal
	{
		next_step.row = next_step.col = rand() % 2 == 0 ? 5 : -5;
	}
}

void Shark::setLocation()
{
	loc += next_step;
}

void Shark::stop()
{
	if (!isStop)
	{
		isStop = true;
		setRandStep();
	}
}
