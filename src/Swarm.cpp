#include "Swarm.hpp"

/**
 * Swarm class implementation
 */

/**
 * Swarm class constructor
 */
Swarm::Swarm() {}

/**
 * method to populate swarm vector with particles
 * @param l - the lower bound for dimension space
 * @param h - the upper bound
 * @param d - the dimensionality
 * @param r - the random seed
 */
void Swarm::populateSwarm(double l, double h, unsigned int d, unsigned int s, int r) {
	srand(r);
	for (unsigned int i = 0; i < s; i++) {
		std::array<double, 30> vel;
		std::array<double, 30> pos;
		for (unsigned int j = 0; j < d; j++) {
			// randomly generate a position [-5.12..5.12] in all dimensions
			pos[j] = l + (double)(rand() / (double)(RAND_MAX)) * (h - l);
			// initial velocity is zero
			vel[j] = 0.00;
		}
		// add it to the swarm
		swarm.push_back(Particle(pos, vel));
	}
}

/**
 * method to find the best global position and fitness
 * essentially just a driver for submethods
 */
void Swarm::findBestInRun() {
	// zero indexed swarm, assume first is best (likely overwritten later)
	int tempIndex = 0;
	// likewise a temporary best fitness
	double tempBest = swarm[0].getFitness();
	for (unsigned int j = 0; j < getSwarmSize(); j++) {
		// if new best is found
		if (swarm[j].getFitness() < tempBest) {
			// update it
			tempBest = swarm[j].getFitness();
			// and store its index
			tempIndex = j;
		}
	}
	// if the best found earlier is better than previous swarm best
	if (tempBest < getBestInSwarmFit()) {
		// overwrite swarm best fitness and position
		setBestInSwarmPos(swarm[tempIndex].getPosition());
		setBestInSwarmFit(tempBest);
	}
}

// getter methods
unsigned int Swarm::getSwarmSize() { return swarm.size(); }
double Swarm::getBestInSwarmFit() { return bestInSwarmFit; }
std::array<double, 30> Swarm::getBestInSwarmPos() { return bestInSwarmPos; }

// setter methods
void Swarm::setBestInSwarmFit(double f) { bestInSwarmFit = f; }
void Swarm::setBestInSwarmPos(std::array<double, 30> p) { bestInSwarmPos = p; }

// operator method
Particle *Swarm::operator[](int index) {
	return &swarm[index];
}