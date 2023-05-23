#pragma once
#include "Location.h"

using std::string, std::cout, std::endl;

/**
 * @brief The Animal class represents an abstract base class for animals.
 *
 * This class provides common functionality and attributes for different types of animals.
 * It includes methods for moving, changing direction, and managing the animal's location.
 */
class Animal
{
protected:
	std::string _name; ///< The name of the animal
	Location _loc; ///< The current location of the animal
	Location _next_step; ///< The next step or target location of the animal
	bool _isStop; ///< A flag indicating whether the animal is stopped or not

	/**
	 * @brief Sets the location of the animal.
	 *
	 * This method is a pure virtual function that should be implemented by derived classes
	 * to set the location of the animal based on its specific behavior.
	 */
	virtual void setLocation() = 0;

public:
	/**
	 * @brief Constructs an Animal object with the given name and location.
	 *
	 * @param name The name of the animal.
	 * @param loc The initial location of the animal.
	 */
	Animal(const std::string& name, const Location& loc);

	/**
	 * @brief Prints the details of the animal.
	 *
	 * This is a pure virtual function that should be implemented by derived classes
	 * to print the specific details of the animal.
	 */
	virtual void printDetails() const = 0;

	/**
	 * @brief Gets the initial character representation of the animal.
	 *
	 * This is a pure virtual function that should be implemented by derived classes
	 * to return the initial character representation of the animal.
	 *
	 * @return The initial character representation of the animal.
	 */
	virtual char getInitial() const = 0;

	/**
	 * @brief Stops the animal.
	 *
	 * This is a pure virtual function that should be implemented by derived classes
	 * to stop the animal's movement or behavior.
	 */
	virtual void stop() = 0;

	/**
	 * @brief Moves the animal to the next step or target location.
	 *
	 * This method updates the animal's current location to the next step or target location.
	 */
	virtual void step();

	/**
	 * @brief Moves the animal to its next step or target location.
	 *
	 * This method moves the animal from its current location to the next step or target location.
	 * It calls the `setLocation` method to update the animal's location based on its specific behavior.
	 */
	void move();

	/**
	 * @brief Gets the current location of the animal.
	 *
	 * @return The current location of the animal.
	 */
	Location getLocation() const;

	/**
	 * @brief Turns the animal horizontally.
	 *
	 * This method changes the direction of the animal to face horizontally.
	 */
	void turnHorizontally();

	/**
	 * @brief Turns the animal vertically.
	 *
	 * This method changes the direction of the animal to face vertically.
	 */
	void turnVertically();
};
