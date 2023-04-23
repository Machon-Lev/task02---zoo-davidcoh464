#pragma once

#include"Animal.h"

class Owl : public Animal
{
	void setLocation()override;
public:
	Owl(const string & _name, const Location & _loc) : Animal(_name, _loc)
	{
		int num_step = rand() % 2 == 0 ? 3 : -3;
		next_step.col = next_step.row = num_step;
	}
	void printDetails()const override { cout << name << "-" << "Owl " << loc; }
	char getInitial()const override { return 'O'; }
	void stop() override;
};