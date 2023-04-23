#pragma once

#include"Animal.h"

class Lion : public Animal
{
	void setLocation()override;
	
public:
	Lion(const string& _name, const Location& _loc) :Animal(_name, _loc)
	{
		next_step.col = rand() % 2 == 0 ? 2 : -2;
		next_step.row = 0;
	}
	void printDetails()const override { cout << name << "-" << "Lion " << loc; }
	char getInitial()const override { return 'L'; }
	void stop() override;
};