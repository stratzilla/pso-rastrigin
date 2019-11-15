#include "Swarm.hpp"
#include <iostream>

/**
 * Random Search class definition
 */
 
class RandSearch {
	private:
		// RandSearch class attribute
		Swarm particleList; // the particle list
	public:
		RandSearch(unsigned int, int); // constructor
		
		// member methods
		void performSearch(); // search method
		void printParams(int);
};