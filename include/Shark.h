#pragma once

#include"Animal.h"

class Shark : public Animal
{
	void setRandStep();
	void setLocation()override;
public:
	Shark(const string& name, const Location& loc);
	void printDetails()const override;
	char getInitial()const override;
	void stop() override;
};