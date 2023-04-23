#pragma once

#include"Animal.h"

class Goose : public Animal
{
	void setLocation()override;
public:
	Goose(const string& _name, const Location& _loc) :Animal(_name, _loc)
	{
		next_step.col = rand() % 2 == 0 ? 1 : -1;
		next_step.row = 1;
	}
	void printDetails()const override { cout << name << "-" << "Goose " << loc; }
	char getInitial()const override { return 'G'; }
	void stop() override;
};
