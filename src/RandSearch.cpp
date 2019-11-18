#include "RandSearch.hpp"

/**
 * RandSearch class implementation
 */
 
const static unsigned int DIMENSIONS = 30;
const static int LOW = -5.12, HIGH = 5.12;

/**
 * RandSearch class constructor
 * @param numSamples - how many particles
 * @param r - the random seed used
 */
RandSearch::RandSearch(unsigned int numSamples, int r) {
	// populate the particle list
	swarm.populateSwarm(LOW, HIGH, DIMENSIONS, numSamples, r);
	// remind user of parameters used
	printParams(r);
}

/**
 * method to perform random search
 */
void RandSearch::performSearch() {
	swarm.setBestInSwarmFit(swarm[0]->getFitness());
	swarm.getBestInSwarmFit();
	std::cout << "Best fitness for " << swarm.getSwarmSize() << " random particles is " << swarm.getBestInSwarmFit() << "." << std::endl;
}

/**
 * method to print random search parameters to user
 * @param r - the random seed used
 */
void RandSearch::printParams(int r) {
	std::cout << "Using paramaters:" << std::endl;
	std::cout << "Swarm Size = " << swarm.getSwarmSize() << std::endl;
	std::cout << "Dimensions = " << DIMENSIONS << std::endl;
	std::cout << "Random Seed = " << r << "\n" << std::endl;
}