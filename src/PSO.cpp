#include "PSO.hpp"

/**
 * PSO class implementation
 */

// to avoid magic numbers later, make these static
const static unsigned int DIMENSIONS = 30;
const static double LOW = -5.12, HIGH = 5.12;

/**
 * PSO class constructor
 * @param w - intertia weight
 * @param cA - cognitive acceleration
 * @param sA - social acceleration
 * @param ss - swarm size
 * @param i - number of epochs
 * @param r - random seed
 */
PSO::PSO(double w, double cA, double sA, unsigned int ss, unsigned int i, int r) {
	weight = w; cogAcc = cA; socAcc = sA; iterations = i;
	swarm.populateSwarm(LOW, HIGH, DIMENSIONS, ss, r); // make the swarm
	srand(r); // init random seed
	printParams(r); // output params to user
}

/**
 * method to perform the PSO search with provided params
 */
void PSO::performSearch() {
	// we need some placeholder for best place winners for vel and pos
	swarm.setBestInSwarmPos(swarm[0]->getPosition()); // the first will do
	swarm.setBestInSwarmFit(swarm[0]->getFitness());
	for (unsigned int i = 0; i <= getIterations(); i++) {
		if (i % 10 == 0) { bestInRun(i); } // output epoch details every 10 epochs
		swarm.findBestInRun();
		// the primary complex for changing particle params
		for (unsigned int j = 0; j < swarm.getSwarmSize(); j++) {
			std::array<double, 30> newPosition; // new particle position 
			std::array<double, 30> newVelocity; // new particle velocity
			for (unsigned int k = 0; k < DIMENSIONS; k++) {
				/**
				 * update velocity based on cognitive and social
				 * accelerations and other PSO parameters
				 */
				double wei = getWeight() * swarm[j]->getVelocity()[k];
				// split for readability
				double cog = getCogAcc() * (double)(rand() / (double)(RAND_MAX));
				double soc = getSocAcc() * (double)(rand() / (double)(RAND_MAX));
				cog *= (swarm[j]->getBestPosition()[k] - swarm[j]->getPosition()[k]);
				soc *= (swarm.getBestInSwarmPos()[k] - swarm[j]->getPosition()[k]);
				newVelocity[k] = wei + cog + soc;
				/**
				 * update particle positions based on new
				 * found velocities
				 */
				newPosition[k] = swarm[j]->getPosition()[k] + newVelocity[k];
			}
			// update the particle with new velocity and position
			swarm[j]->setPosition(newPosition);
			swarm[j]->setVelocity(newVelocity);
		}
		// update swarm particles to set best if fitness is better than old best
		for (unsigned int j = 0; j < swarm.getSwarmSize(); j++) {
			// only update personal best when within constraints
			if (!swarm[j]->isOutOfBounds(LOW, HIGH)) { swarm[j]->setBestValues(); }
		}
	}
}

/**
 * method to display the best in epoch iteration
 * @param i - the iteration
 */
void PSO::bestInRun(unsigned int i) {
	double avg = 0.00;
	for (unsigned int j = 0; j < swarm.getSwarmSize(); j++) {
		avg += swarm[j]->getFitness();
	}
	avg /= swarm.getSwarmSize();
	std::cout << "Epoch " << i << ": best fitness is " << swarm.getBestInSwarmFit() << ", average is " << avg << std::endl;
}

/**
 * method to print PSO parameters to user
 * @param r - the random seed used
 */
void PSO::printParams(int r) {
	std::cout << "Using paramaters:" << std::endl;
	std::cout << "\u03C9 = " << getWeight() << std::endl;
	std::cout << "C_1 = " << getCogAcc() << std::endl;
	std::cout << "C_2 = " << getSocAcc() << std::endl;
	std::cout << "Swarm Size = " << swarm.getSwarmSize() << std::endl;
	std::cout << "Iterations = " << getIterations() << std::endl;
	std::cout << "Dimensions = " << DIMENSIONS << std::endl;
	std::cout << "Random Seed = " << r << "\n" << std::endl;
}

// getter methods
unsigned int PSO::getIterations() { return iterations; }
double PSO::getWeight() { return weight; }
double PSO::getCogAcc() { return cogAcc; }
double PSO::getSocAcc() { return socAcc; }