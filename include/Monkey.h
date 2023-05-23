#pragma once
#include"Animal.h"

class Monkey : public Animal
{
	int _counter;
	void setRandStep();
	void setLocation()override;
public:
	Monkey(const string& name, const Location& loc);
	void printDetails()const override;
	char getInitial()const override;
	void stop() override;
};