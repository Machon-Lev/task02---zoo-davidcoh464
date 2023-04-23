#pragma once
#include"Animal.h"


class Dog : public Animal
{
	void setLocation()override;
public:
	Dog(const string& _name, const Location& _loc) :Animal(_name, _loc) 
	{
		next_step.col = rand() % 2  == 0 ? 3 : -3;
		next_step.row = 0;
	}
	void printDetails()const override { cout << name << "-" << "Dog " << loc; }
	char getInitial()const override { return 'D'; }
	void stop() override;
};