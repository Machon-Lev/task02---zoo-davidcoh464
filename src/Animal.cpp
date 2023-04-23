#include "Animal.h"
void Animal::step()
{
	if (!isStop)
	{
		setLocation();
	}
}

