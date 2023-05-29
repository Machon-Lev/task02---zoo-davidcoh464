#pragma once

#include"Animal.h"

class Lion : public Animal
{
	void setLocation()override;
public:
	Lion(const string& name, const Location& loc);
	void printDetails()const override;
	char getInitial()const override;
	void stop() override;
};