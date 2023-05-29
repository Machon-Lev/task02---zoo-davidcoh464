#pragma once

#include"Animal.h"

class Goose : public Animal
{
	void setLocation()override;
public:
	Goose(const string& name, const Location& loc);
	void printDetails()const override;
	char getInitial()const override;
	void stop() override;
};
