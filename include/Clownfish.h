#pragma once

#include"Animal.h"

class Clownfish: public Animal
{
	void setRandStep();
	void setLocation()override;
public:
	Clownfish(const string& _name, const Location& _loc) : Animal(_name, _loc)
	{
		setRandStep();
	}
	void printDetails()const override { cout << name << "-" << "Clownfish " << loc; }
	char getInitial()const override { return 'C'; }
	void stop() override;
};
