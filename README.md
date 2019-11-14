# PSO-Rastrigin

A vanilla particle swarm optimization algorithm to approximate the global minimum of the Rastrigin function. This is in 30-dimensions. Additionally is a random search algorithm to compare and contrast between random and PSO.

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

This is using a swarm size of 50 and 500 iterations.
For random search, this is 25000 particles.

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
- C++ (0x or higher)
- GNU/Linux
