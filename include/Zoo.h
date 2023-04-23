#pragma once
#include"Lion.h"
#include"Dog.h"
#include"Clownfish.h"
#include"Goose.h"
#include"Monkey.h"
#include"Owl.h"
#include"Shark.h"
#include<vector>
#include<string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <functional>

using std::unique_ptr, std::make_unique;

class Zoo
{
	std::vector<unique_ptr<Animal>> animals;
	enum AnimalType
	{
		CLOWNFISH, DOG, GOOSE, LION, MONKEY, OWL, SHARK
	};

	void stop(int index);
	void move(int index);
	void step();
	void create(AnimalType type, string name);
	void del(int index);
	void delAll(AnimalType type);
	void help() const;
	void printMap()const;
	void printList() const;
	AnimalType toAnimalType(const std::string& str)const;
	void toLower(string& s) const;

public:

	Zoo();
	void run();
};
