# PSO Rastrigin

A vanilla particle swarm optimization algorithm to approximate the global minimum of the Rastrigin function. This is in 30-dimensions. Additionally, there is a random search algorithm to compare and contrast between random and PSO.

# Compilation and Execution

Compile with the below:

`$ g++ source.cpp PSO.cpp RandSearch.cpp Swarm.cpp Particle.cpp -o psor`

With execution as below:

`$ ./psor <args>`

Where `<args>` is either two arguments or six.

When using two arguments for a predefined test:

```
<arg1> - Premade Test
    1. ω = 0.729844, c1 = c2 = 1.496180
    2. ω = 0.4, c1 = c2 = 1.2
    3. ω = 1.0, c1 = c2 = 2.0
    4. ω = -1.0, c1 = c2 = 2.0
    5. Randomized Search
<arg2> - Random Seed
```

This is using a swarm size of 50 and 500 iterations. For random search, this is 25000 particles.

Or, using six arguments for a custom test:

```
<arg1> - Intertia Weight (ω)
<arg2> - Cognitive Acceleration Coefficient (C1)
<arg3> - Social Acceleration Coefficient (C2)
<arg4> - Swarm Size
<arg5> - Number of Iterations
<arg6> - Random Seed
```

# Dependencies

- gcc/g++
- C++ (0x or higher, may need `-std=c++0x` flag)
- GNU/Linux

# Particle Swarm

By generating a swarm of particles with initial velocities of zero and initial positions randomly distributed, an iterative process ensures particles "move" within the search space towards a solution. The iterative step is a function of a particle's position, velocity, and its fitness. For this algorithm the Rastrigin function is used as fitness evaluation.

The iterative step can be defined as below:

<img src="https://latex.codecogs.com/png.latex?p_i%28t&plus;1%29%20%3D%20p_i%28t%29%20&plus;%20v_i%28t&plus;1%29"/>
<img src="https://latex.codecogs.com/png.latex?v_i%28t&plus;1%29%20%3D%20%5Comega%20v_i%28t%29%20&plus;%20c_1%20r_1%28y%28t%29%20-%20x_i%28t%29%29%20&plus;%20c_2%20r_2%28%5Chat%7By%7D%28t%29-x_i%28t%29%29"/>

Where <img src="https://latex.codecogs.com/png.latex?t"/> is some time (and therefore <img src="https://latex.codecogs.com/png.latex?t+1"/> is the next time step), <img src="https://latex.codecogs.com/png.latex?v"/> is the velocity of the particle, <img src="https://latex.codecogs.com/png.latex?p"/> is the position of the particle, <img src="https://latex.codecogs.com/png.latex?y"/> is the personal best fitness of the particle, and <img src="https://latex.codecogs.com/png.latex?%5Chat%7By%7D"/> is the swarm personal best fitness.

The remaining terms are user defined: <img src="https://latex.codecogs.com/png.latex?\omega"/> is the intertial weight (resistance to change in velocity), <img src="https://latex.codecogs.com/png.latex?c_1"/> is the cognitive acceleration coefficient (how much the personal fitness impacts the velocity), and <img src="https://latex.codecogs.com/png.latex?c_2"/> is the social acceleration coefficient (how much the swarm fitness impacts the velocity). <img src="https://latex.codecogs.com/png.latex?r_1,r_2"/> are random multiplicands to ensure stochasticity.

After each iteration, every particle has their velocities, positions, and fitnesses updated. Over time, the swarm will approximate to a solution to the fitness function.

# Rastrigin Function

The fitness of a particle is determined by the Rastrigin function. A particle's fitness is found by performing the below equation with its position as argument.

<img src="https://latex.codecogs.com/png.latex?f%28x%29%20%3D%2010n_x%20&plus;%20%5Csum%5E%7Bn_x%7D_%7Bi%3D1%7D%20%28x_i%5E2%20-%2010%5Ccos%7B%282%5Cpi%20x_i%29%7D%29"/>

Where <img src="https://latex.codecogs.com/png.latex?n_x"/> is the dimensionality of the problem, <img src="https://latex.codecogs.com/png.latex?x_i"/> is some position in the search space in the <img src="https://latex.codecogs.com/png.latex?i"/>th dimension and each <img src="https://latex.codecogs.com/png.latex?x_i%20%5Cin%20%5B-5.12%2C%205.12%5D">. An optimal solution to this function is <img src="https://latex.codecogs.com/png.latex?0"/>.

After each epoch, the fitness of a particle is re-evaluation using this function and given enough epochs (and careful PSO parameters chosen as mentioned before), each particle will tend closer to the function minimum.

# Performance

This algorithm was created as an exercise in PSO and to compare differing parameters to determine their impact on algorithmic efficacy. Refer to the predefined tests as previously mentioned for the specific tests I performed. The first two test results are below (graphing fitness over time):

<img src="https://github.com/stratzilla/pso-rastrigin/blob/master/img/test1.png"/> <img src="https://github.com/stratzilla/pso-rastrigin/blob/master/img/test2.png"/>

The first test converges slowly but maintains a better final fitness, whereas the second test converges rapidly to a solution that is not as fit. The remaining two tests are insignificant other than the swarm fitness tends to be equivalent to random uniform search.
