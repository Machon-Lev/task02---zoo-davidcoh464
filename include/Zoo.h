#pragma once
#include "Lion.h"
#include "Dog.h"
#include "Clownfish.h"
#include "Goose.h"
#include "Monkey.h"
#include "Owl.h"
#include "Shark.h"
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <functional>

using std::unique_ptr, std::make_unique;

/**
 * @brief The Zoo class represents a zoo that manages various types of animals.
 *
 * This class provides functionality to interact with animals in the zoo.
 * It allows creating, deleting, moving, and stopping animals, as well as providing help and information about the zoo.
 */
class Zoo
{
	std::vector<unique_ptr<Animal>> _animals; ///< The collection of animals in the zoo
	std::unordered_map<std::string_view, std::function<void()>> _commandMap; ///< The map of commands and their corresponding functions

	enum AnimalType
	{
		CLOWNFISH, DOG, GOOSE, LION, MONKEY, OWL, SHARK
	};

	/**
	 * @brief Stops the animal at the specified index.
	 *
	 * @param index The index of the animal in the collection to stop.
	 */
	void stop(int index);

	/**
	 * @brief Moves the animal at the specified index.
	 *
	 * @param index The index of the animal in the collection to move.
	 */
	void move(int index);

	/**
	 * @brief Moves all animals in the zoo by one step.
	 */
	void step();

	/**
	 * @brief Creates an animal of the specified type with the given name.
	 *
	 * @param type The type of the animal to create.
	 * @param name The name of the animal.
	 */
	void create(AnimalType type, string name);

	/**
	 * @brief Deletes the animal at the specified index.
	 *
	 * @param index The index of the animal in the collection to delete.
	 */
	void del(int index);

	/**
	 * @brief Deletes all animals of the specified type.
	 *
	 * @param type The type of the animals to delete.
	 */
	void delAll(AnimalType type);

	/**
	 * @brief Prints the available commands and their descriptions.
	 */
	void help() const;

	/**
	 * @brief Prints the Zoo map.
	 */
	void printMap() const;

	/**
	 * @brief Prints the Zoo list.
	 */
	void printList() const;

	/**
	 * @brief Converts a string to an AnimalType value.
	 *
	 * @param str The string representation of the animal type.
	 * @return The corresponding AnimalType value.
	 */
	AnimalType toAnimalType(const std::string& str) const;

	/**
	 * @brief Converts a string to lowercase.
	 *
	 * @param s The string to convert to lowercase.
	 */
	void toLower(string& s) const;

	/**
	 * @brief Sets up the command map with available commands and their corresponding functions.
	 */
	void setCommandMap();

public:
	/**
	 * @brief Constructs a Zoo object.
	 */
	Zoo();

	/**
	 * @brief Runs the zoo application.
	 */
	void run();
};
