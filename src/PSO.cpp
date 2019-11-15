#include "PSO.hpp"

/**
 * PSO class implementation
 */

// to avoid magic numbers later, make these static
static unsigned int DIMENSIONS = 30;
static double LOW = -5.12, HIGH = 5.12;

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
void PSO::performPSO() {
	// we need some placeholder for best place winners for vel and pos
	setBestInSwarmPos(swarm[0]->getPosition()); // the first will do
	setBestInSwarmFit(swarm[0]->getFitness());
	for (unsigned int i = 0; i <= getIterations(); i++) {
		if (i % 10 == 0) { bestInRun(i); } // output epoch details every 10 epochs
		findBestInRun();
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
				soc *= (getBestInSwarmPos()[k] - swarm[j]->getPosition()[k]);
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
 * method to find the best global position and fitness
 * essentially just a driver for submethods
 */
void PSO::findBestInRun() {
	// zero indexed swarm, assume first is best (likely overwritten later)
	int tempIndex = 0;
	// likewise a temporary best fitness
	double tempBest = swarm[0]->getFitness();
	for (unsigned int j = 0; j < swarm.getSwarmSize(); j++) {
		// if new best is found
		if (swarm[j]->getFitness() < tempBest) {
			// update it
			tempBest = swarm[j]->getFitness();
			// and store its index
			tempIndex = j;
		}
	}
	// if the best found earlier is better than previous swarm best
	if (tempBest < getBestInSwarmFit()) {
		// overwrite swarm best fitness and position
		setBestInSwarmPos(swarm[tempIndex]->getPosition());
		setBestInSwarmFit(tempBest);
	}
}

/**
 * method to display the best in epoch iteration
 * @param i - the iteration
 */
void PSO::bestInRun(unsigned int i) {
	double avg = 0.00;
	for (int j = 0; j < swarm.getSwarmSize(); j++) {
		avg += swarm[j]->getFitness();
	}
	avg /= swarm.getSwarmSize();
	// (used to make graphs) std::cout << i << " " << getBestInSwarmFit() << " " << avg << std::endl;
	std::cout << "Epoch " << i << ": best fitness is " << getBestInSwarmFit() << ", average is " << avg << std::endl;
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
double PSO::getBestInSwarmFit() { return bestInSwarmFit; }
std::array<double, 30> PSO::getBestInSwarmPos() { return bestInSwarmPos; }

// setter methods
void PSO::setBestInSwarmFit(double f) { bestInSwarmFit = f; }
void PSO::setBestInSwarmPos(std::array<double, 30> p) { bestInSwarmPos = p; }