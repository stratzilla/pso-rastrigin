#include "PSO.hpp"
#include "RandSearch.hpp"

// in case of error (unlikely), use these values for PSO
unsigned int SWARM_SIZE = 30;
unsigned int ITERATIONS = 500;
double OMEGA = 0.729844;
double C_1 = 1.496180;
double C_2 = 1.496180;
bool IS_RANDOM = false;
int RAN = 0;

/**
 * function to remind the user of proper compilation and execution
 */
void printHelp() {
	std::cout << "\nCompile and execute the program as so:\n" << std::endl;
	std::cout << " $ g++ source.cpp Particle.cpp PSO.cpp Swarm.cpp RandSearch.cpp -o psor" << std::endl;
	std::cout << " $ ./psor <args>\n" << std::endl;
	std::cout << "Where you can use two arguments:" << std::endl;
	std::cout << " <arg1> - Premade Test" << std::endl;
	std::cout << "	1. \u03C9 = 0.729844, c1 = c2 = 1.496180" << std::endl;
	std::cout << "	2. \u03C9 = 0.4, c1 = c2 = 1.2" << std::endl;
	std::cout << "	3. \u03C9 = 1.0, c1 = c2 = 2.0" << std::endl;
	std::cout << "	4. \u03C9 = -1.0, c1 = c2 = 2.0" << std::endl;
	std::cout << "	5. Randomized Search" << std::endl;
	std::cout << " <arg2> - Random Seed" << std::endl;
	std::cout << "This is using a swarm size of " << SWARM_SIZE << " and " << ITERATIONS << " iterations." << std::endl;
	std::cout << "For random search, this is " << SWARM_SIZE * ITERATIONS << " particles." << std::endl;
	std::cout << "\nOr, using six arguments:" << std::endl;
	std::cout << " <arg1> - Intertia Weight (\u03C9)" << std::endl;
	std::cout << " <arg2> - Cognitive Acceleration Coefficient (C1)" << std::endl;
	std::cout << " <arg3> - Social Acceleration Coefficient (C2)" << std::endl;
	std::cout << " <arg4> - Swarm Size" << std::endl;
	std::cout << " <arg5> - Number of Iterations" << std::endl;
	std::cout << " <arg6> - Random Seed\n" << std::endl;
}

/**
 * main driver, entry point
 */
int main(int argc, char** argv) {
	if (argc == 3) { // if enough arguments for predefined searches
		switch(atoi(argv[1])) {
			case 1: OMEGA = 0.729844; C_1 = C_2 = 1.496180; break;
			case 2: OMEGA = 0.4; C_1 = C_2 = 1.2; break;
			case 3: OMEGA = 1.0; C_1 = C_2 = 2.0; break;
			case 4: OMEGA = -1.0; C_1 = C_2 = 2.0; break;
			case 5: IS_RANDOM = true; break;
			default: printHelp(); return 0;
		}
		RAN = atoi(argv[2]);
	} else if (argc == 7) { // if enough arguments for user-defined searches
		OMEGA = atof(argv[1]); C_1 = atof(argv[2]); C_2 = atof(argv[3]);
		SWARM_SIZE = atoi(argv[4]); ITERATIONS = atoi(argv[5]); RAN = atoi(argv[6]);
	} else { // otherwise throw error
		printHelp();
		return 0;
	}
	if (!IS_RANDOM) { // if not random
		// construct the PSO object
		PSO p(OMEGA, C_1, C_2, SWARM_SIZE, ITERATIONS, RAN);
		// and perform PSO search upon it
		p.performSearch();
	} else { // if random
		// construct the RandomSearch object
		RandSearch r(SWARM_SIZE * ITERATIONS, RAN);
		// and perform the random search upon it
		r.performSearch();
	}
	return 0;
}
