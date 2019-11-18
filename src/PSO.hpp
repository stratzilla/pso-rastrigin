#include <iostream>
#include <stdlib.h>
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
		unsigned int iterations; // epoch count
		
		// private member methods
		void bestInRun(unsigned int);
		void printParams(int);
		
		// getter methods
		double getWeight();
		double getCogAcc();
		double getSocAcc();
		unsigned int getIterations();
	public:
		// PSO constructor
		PSO(double, double, double, unsigned int, unsigned int, int);
		
		// public member method
		void performSearch();
};