#pragma once
#include"Animal.h"

class Monkey : public Animal
{
	int counter;
	void setRandStep();
	void setLocation()override;
public:
	Monkey(const string& _name, const Location& _loc) :Animal(_name, _loc), counter(0)
	{
		setRandStep();
	}
	void printDetails()const override { cout << name << "-" << "Monkey " << loc; }
	char getInitial()const override { return 'M'; }
	void stop() override;
};