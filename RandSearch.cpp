#include "RandSearch.hpp"

/**
 * RandSearch class implementation
 */
 
static unsigned int DIMENSIONS = 30;
static int LOW = -5.12, HIGH = 5.12;

/**
 * RandSearch class constructor
 * @param numSamples - how many particles
 * @param r - the random seed used
 */
RandSearch::RandSearch(unsigned int numSamples, int r) {
	// populate the particle list
	particleList.populateSwarm(LOW, HIGH, DIMENSIONS, numSamples);
	// remind user of parameters used
	printParams(r);
}

/**
 * method to perform random search
 */
void RandSearch::performSearch() {
	// temporarily assume first particle is best
	double tempBest = particleList[0]->getFitness();
	// check over each particle to see if its better
	for (unsigned int i; i < particleList.getSwarmSize(); i++) {
		// if new best is found
		if (particleList[i]->getFitness() < tempBest) {
			// update it
			tempBest = particleList[i]->getFitness();
		}
	}
	std::cout << "Best fitness for " << particleList.getSwarmSize() << " random particles is " << tempBest << "." << std::endl;
}

/**
 * method to print random search parameters to user
 * @param r - the random seed used
 */
void RandSearch::printParams(int r) {
	std::cout << "Using paramaters:" << std::endl;
	std::cout << "Swarm Size = " << particleList.getSwarmSize() << std::endl;
	std::cout << "Dimensions = " << DIMENSIONS << std::endl;
	std::cout << "Random Seed = " << r << "\n" << std::endl;
}