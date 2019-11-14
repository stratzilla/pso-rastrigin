#include <iostream>
#include "Particle.hpp"
#include "Swarm.hpp"

/**
 * PSO class definition
 */

class PSO {
	private:
		// PSO class attributes
		Swarm swarm; // the particle swarm
		double weight; // intertia weight
		double cogAcc; // cognitive acceleration
		double socAcc; // social acceleration
		unsigned int swarmSize; // how many particles
		unsigned int iterations; // epoch count
		double bestInSwarmFit; // best fitness for swarm
		std::array<double, 30> bestInSwarmPos; // best location for swarm
		
		// private member methods
		void findBestInRun();
		void bestInRun(unsigned int);
		void printParams(int);
		
		// getter methods
		double getWeight();
		double getCogAcc();
		double getSocAcc();
		unsigned int getIterations();
		double getBestInSwarmFit();
		std::array<double, 30> getBestInSwarmPos();
		
		// setter methods
		void setBestInSwarmFit(double);
		void setBestInSwarmPos(std::array<double, 30>);
	public:
		// PSO constructor
		PSO(double, double, double, unsigned int, unsigned int, int);
		
		// public member method
		void performPSO();
};