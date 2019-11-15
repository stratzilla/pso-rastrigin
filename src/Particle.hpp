#pragma once
#include <array>
#include <math.h>

/**
 * Particle class definition
 */

class Particle {
	private:
		// attributes for Particle
		double fitness; // fitness of the particle
		double bestFitness; // the best fitness
		std::array<double, 30> position; // pos of particle
		std::array<double, 30> bestPosition; // the best position
		std::array<double, 30> velocity; // velocity of particle
		
		// private member method
		double rastriginEvaluation(std::array<double, 30>);
	public:
		// constructor
		Particle(std::array<double, 30>, std::array<double, 30>);
		
		// public member methods
		void setBestValues();
		bool isOutOfBounds(int, int);
		
		// getter methods
		double getFitness();
		double getBestFitness();
		std::array<double, 30> getPosition();
		std::array<double, 30> getBestPosition();
		std::array<double, 30> getVelocity();
		
		// setter methods
		void setFitness(double);
		void setBestFitness(double);
		void setPosition(std::array<double, 30>);
		void setBestPosition(std::array<double, 30>);
		void setVelocity(std::array<double, 30>);
};
