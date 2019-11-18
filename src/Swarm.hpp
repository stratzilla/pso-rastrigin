#pragma once
#include "Particle.hpp"
#include <vector>
#include <stdlib.h>

/**
 * Swarm class definition
 */
 
class Swarm {
	private:
		// Swarm class attributes
		double bestInSwarmFit; // best fitness for swarm
		std::array<double, 30> bestInSwarmPos; // best location for swarm
		std::vector<Particle> swarm; // the swarm itself
	public:
		Swarm(); // constructor
		
		// member method
		void populateSwarm(double, double, unsigned int, unsigned int, int);
		void findBestInRun();
		
		// getter methods
		unsigned int getSwarmSize();
		double getBestInSwarmFit();
		std::array<double, 30> getBestInSwarmPos();
		
		// setter methods
		void setBestInSwarmFit(double);
		void setBestInSwarmPos(std::array<double, 30>);
		
		// operator to index swarm
		Particle *operator[](int);
};