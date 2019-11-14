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

// getter method
unsigned int Swarm::getSwarmSize() { return swarm.size(); }

// operator method
Particle *Swarm::operator[](int index) {
	return &swarm[index];
}