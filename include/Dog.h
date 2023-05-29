#pragma once
#include"Animal.h"


class Dog : public Animal
{
	void setLocation()override;
public:
	Dog(const string& name, const Location& loc);
	void printDetails()const override;
	char getInitial()const override;
	void stop() override;
};