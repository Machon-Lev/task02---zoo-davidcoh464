#pragma once

#include"Animal.h"

class Owl : public Animal
{
	void setLocation()override;
public:
	Owl(const string& name, const Location& loc);
	void printDetails()const override;
	char getInitial()const override;
	void stop() override;
};