#pragma once

#include"Animal.h"

class Shark : public Animal
{
	void setRandStep();
	void setLocation()override;
public:
	Shark(const string& _name, const Location& _loc) : Animal(_name, _loc)
	{
		setRandStep();
	}
	void printDetails()const override { cout << name << "-" << "Shark " << loc; }
	char getInitial()const override { return 'S'; }
	void stop() override;
};