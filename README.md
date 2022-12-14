# Project 2: Load Balancer
## Getting Started
- Use click this [link](http://people.tamu.edu/~hoaannguyen07/csce-412/project2/documentation/index.html) to view the documentation for this Load Balancer implementing the round-robin technique.

## Compilation and Running 
If you have `cmake` installed, run `make` to run and start the simulation.

Otherwise, run the following command:
```
g++ -O -o LoadBalancingSimulator.exe main.cpp request.cpp request-queue.cpp server.cpp server-group.cpp load-balancer.cpp test-load-balancer.cpp && ./LoadBalancingSimulator.exe
```

Enter the character `d` to choose the default option or `c` to choose the custom option for the load balancer simulation.

## Simulation Options
- Default option `d`: Default load balancing option (`num cycles: 10,000`, `num servers: 10`)
- Custom option `c`: Custom load balancing option