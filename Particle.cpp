#include "Particle.hpp"

/**
 * Particle class implementation
 */

/**
 * Particle class constructor
 * @param p - the position of the particle
 * @param v - the velocity of the particle
 */
Particle::Particle(std::array<double, 30> p, std::array<double, 30> v) {
	bestFitness = fitness = rastriginEvaluation(p);
	bestPosition = position = p;
	velocity = v;
}

/**
 * rastrigin fitness evaluation function
 * @param p - the position of the particle
 * @return - the evaluation of the rastrigin function of p
 */
double Particle::rastriginEvaluation(std::array<double, 30> p) {
	double d = 10 * sizeof(p)/sizeof(p[0]);
	for (unsigned int i = 0; i < sizeof(p)/sizeof(p[0]); i++) { // for each dimension
		d += (pow(p[i],2) - (10 * cos(2*M_PI * p[i])));
	}
	return d;
}

/**
 * method to update best values to current values
 */
void Particle::setBestValues() {
	// if new fitness is better than old fitness
	if (rastriginEvaluation(position) < getFitness()) {
		// reinit as new pos, bestpos, etc
		setBestFitness(rastriginEvaluation(position));
		setFitness(getBestFitness());
		setBestPosition(getPosition());
		setPosition(getBestPosition());
	}
}

/**
 * method to determine if a particle is out of bounds
 * @param min - the lower bound for dimension position
 * @param max - the upper bound
 * @return - whether particle is out of bounds
 */
bool Particle::isOutOfBounds(int min, int max) {
	std::array<double, 30> p = getPosition(); // find particle position
	for (unsigned int i = 0; i < sizeof(p)/sizeof(p[0]); i++) {
		if (p[i] < min || p[i] > max) { return true; } // if OOB
	}
	return false; // else not OOB
}

// getter methods
double Particle::getFitness() {	return fitness; }
double Particle::getBestFitness() { return bestFitness; }
std::array<double, 30> Particle::getPosition() { return position; }
std::array<double, 30> Particle::getBestPosition() { return bestPosition; }
std::array<double, 30> Particle::getVelocity() { return velocity; }

// setter methods
void Particle::setFitness(double f) { fitness = f; }
void Particle::setBestFitness(double f) { bestFitness = f; }
void Particle::setPosition(std::array<double, 30> p) { position = p; }
void Particle::setBestPosition(std::array<double, 30> p) { bestPosition = p; }
void Particle::setVelocity(std::array<double, 30> v) { velocity = v; }