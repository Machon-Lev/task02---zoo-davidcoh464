#include "Owl.h"

void Owl::setLocation()
{
	if (next_step.col > 0 && (loc.col == COLUMNS - 1 || loc.row == ROWS - 1)
		|| next_step.col < 0 && (loc.col == 0 || loc.row == 0))
		next_step.col = next_step.row = (-1) * next_step.col;
	loc += next_step;
}
void Owl::stop()
{
	if (!isStop)
	{
		isStop = true;
		int num_step = rand() % 2 == 0 ? 3 : -3;
		next_step.col = next_step.row = num_step;
	}
}
