#include "Zoo.h"

void Zoo::stop(int index)
{
	if (index < 0 || index >= _animals.size())
		throw std::out_of_range("Index out of range\n");
	_animals[index]->stop();
}

void Zoo::move(int index)
{
	if (index < 0 || index >= _animals.size())
		throw std::out_of_range("Index out of range\n");
	_animals[index]->move();
}

void Zoo::step()
{
	for (auto& a : _animals)
		a->step();
}

void Zoo::create(AnimalType type, string name)
{
	Location loc;
	switch (type)
	{
	case CLOWNFISH:
		_animals.push_back(make_unique<Clownfish>(name, loc));
		break;
	case DOG:
		_animals.push_back(make_unique<Dog>(name, loc));
		break;
	case GOOSE:
		_animals.push_back(make_unique<Goose>(name, loc));
		break;
	case LION:
		_animals.push_back(make_unique<Lion>(name, loc));
		break;
	case MONKEY:
		_animals.push_back(make_unique<Monkey>(name, loc));
		break;
	case OWL:
		_animals.push_back(make_unique<Owl>(name, loc));
		break;
	case SHARK:
		_animals.push_back(make_unique<Shark>(name, loc));
		break;
	default:
		break;
	}
}

void Zoo::del(int index)
{
	if (index < 0 || index >= _animals.size())
		throw std::out_of_range("Index out of range\n");
	_animals.erase(_animals.begin() + index);
}

void Zoo::delAll(AnimalType type)
{
	char initial;
	switch (type)
	{
	case CLOWNFISH:
		initial = 'C';
		break;
	case DOG:
		initial = 'D';
		break;
	case GOOSE:
		initial = 'G';
		break;
	case LION:
		initial = 'L';
		break;
	case MONKEY:
		initial = 'M';
		break;
	case OWL:
		initial = 'O';
		break;
	case SHARK:
		initial = 'S';
		break;
	default:
		initial = 'a';
		break;
	}
	_animals.erase(
		std::remove_if(_animals.begin(), _animals.end(),
			[initial](const unique_ptr<Animal>& a) {  return a->getInitial() == initial; }),
		_animals.end());
}

void Zoo::help() const
{
	cout << "Help-menu:\n";
	cout << "'stop': Make animal at index (which should be received in the next input) to stop\n";
	cout << "'move': Make animal at index (which should be received in the next input) to move\n";
	cout << "'create': Creates new animal with type and (that receives from the user in the next inputs)\n";
	cout << "'del': Delete animal at index (which should be received in the next input)\n";
	cout << "'delAll': Removes all animal of specific type (receives the type in the next input)\n";
	cout << "'.': Moving to the next turn without change\n";
	cout << "'exit': Exit the program\n";
	cout << "'help': Print the menu of all available commands\n";
	cout << endl;
}

void Zoo::printMap() const
{
	cout << "Zoo-Map:\n";
	for (int r = 0; r < ROWS; ++r)
	{
		for (int c = 0; c < COLUMNS; c++)
		{
			Location loc(r, c);
			bool is_full = false;
			for (auto& animal : _animals)
			{
				if (animal->getLocation() == loc)
				{
					is_full = true;
					cout << animal->getInitial() << " ";
					break;
				}
			}
			if (!is_full)
				cout << "- ";
		}
		cout << endl;
	}
	cout << endl;
}

void Zoo::printList() const
{
	cout << "Zoo-List:\n";
	int index = 0;
	for (auto& animal : _animals)
	{
		cout << index << ". ";
		animal->printDetails();
		cout << endl;
		++index;
	}
	cout << endl;
}

Zoo::AnimalType Zoo::toAnimalType(const std::string& str) const
{

	static const std::map<std::string, AnimalType> animalMap =
	{
		{"clownfish", CLOWNFISH},
		{"dog", DOG},
		{"goose", GOOSE},
		{"lion", LION},
		{"monkey", MONKEY},
		{"owl", OWL},
		{"shark", SHARK}
	};
	auto it = animalMap.find(str);
	if (it == animalMap.end())
		throw std::invalid_argument("Invalid animal type string: " + str);
	return it->second;
}

void Zoo::toLower(string &s) const
{
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
}

void Zoo::setCommandMap()
{
	_commandMap =
	{
		{"stop", [&]() {
			int index;
			std::cout << "Enter index: ";
			std::cin >> index;
			try { stop(index); }
			catch (const std::exception& e) { std::cerr << "Error: " << e.what() << std::endl; }
		}},
		{ "move", [&]() {
			int index;
			std::cout << "Enter index: ";
			std::cin >> index;
			try { move(index); }
			catch (const std::exception& e) { std::cerr << "Error: " << e.what() << std::endl; }
		} },
		{ "create", [&]() {
			AnimalType type;
			std::string name;
			std::cout << "Enter animal type: ";
			std::cin >> std::ws; // ignore white spaces
			std::getline(std::cin, name);
			toLower(name);
			try {
				type = toAnimalType(name);
				std::cout << "Enter animal name: ";
				std::getline(std::cin, name);
				create(type, name);
			}
			catch (const std::exception& e) { std::cerr << "Error: " << e.what() << std::endl; }
		} },
		{ "del", [&]() {
			int index;
			std::cout << "Enter index: ";
			std::cin >> index;
			try { del(index); }
			catch (const std::exception& e) { std::cerr << "Error: " << e.what() << std::endl; }
		} },
		{ "delall", [&]() {
			AnimalType type;
			std::string name;
			std::cout << "Enter animal type: ";
			std::cin >> std::ws; // ignore white spaces
			std::getline(std::cin, name);
			toLower(name);
			try { delAll(toAnimalType(name)); }
			catch (const std::exception& e) { std::cerr << "Error: " << e.what() << std::endl; }
		} },
		{ "help", [&]() { help(); } },
		{ ".", [&]() {} },
		{ "exit", []() { std::exit(0); } }
	};
}

Zoo::Zoo()
{
	create(LION, "Simba");
	create(LION, "Mufasa");
	create(MONKEY, "Rafiki");
	create(GOOSE, "Akka");
	create(GOOSE, "Morten");
	create(OWL, "Hedwig");
	create(DOG, "Toto");
	create(SHARK, "Jaws");
	create(CLOWNFISH, "Nemo");

	setCommandMap();
}

void Zoo::run()
{
	printMap();
	printList();

	std::string line;
	std::cout << "Enter command: ";
	while (std::getline(std::cin, line)) 
	{
		toLower(line);
		const auto it = _commandMap.find(line);
		if (it == _commandMap.end())
		{
			std::cerr << "Error: unknown command '" << line << "'" << std::endl;
			cout << "Enter command again: ";
			std::cin >> std::ws; // ignore white spaces
			continue;
		}
		else { it->second(); }
		
		if (line != "help")
		{
			step();
			printMap();
			printList();
		}
		
		std::cout << "Enter command: ";
		std::cin >> std::ws; // ignore white spaces
	}
}
