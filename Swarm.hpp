#pragma once
#include "Particle.hpp"
#include <vector>

/**
 * Swarm class definition
 */
 
class Swarm {
	private:
		// Swarm class attribute
		std::vector<Particle> swarm; // the swarm itself
	public:
		Swarm(); // constructor
		
		// member method
		void populateSwarm(double, double, unsigned int, unsigned int);
		
		// getter method
		unsigned int getSwarmSize();
		
		// operator to index swarm
		Particle *operator[](int);
};