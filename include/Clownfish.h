#pragma once

#include"Animal.h"

class Clownfish: public Animal
{
	void setRandStep();
	void setLocation()override;
public:
	Clownfish(const string& name, const Location& loc);
	void printDetails()const override;
	char getInitial()const override;
	void stop() override;
};
