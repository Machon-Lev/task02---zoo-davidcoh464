#include"Clownfish.h"

void Clownfish::setRandStep()
{
	int val = rand();
	if (val % 3 == 0) // horizntal
	{
		next_step.col = rand() % 2 == 0 ? 1 : -1;
	}
	else if (val % 3 == 1) // vertical
	{
		next_step.row = rand() % 2 == 0 ? 1 : -1;
	}
	else // diagonal
	{
		next_step.row = next_step.col = rand() % 2 == 0 ? 1 : -1;
	}
}

void Clownfish::setLocation()
{
	loc += next_step;
}

void Clownfish::stop()
{
	if (!isStop)
	{
		isStop = true;
		setRandStep();
	}
}
