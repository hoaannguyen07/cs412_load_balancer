#ifndef TESTLOADBALANCER_HPP
#define TESTLOADBALANCER_HPP

class TestLoadBalancer
{
private:
    /* data */
public:
    TestLoadBalancer() {};
    ~TestLoadBalancer() {};

    /**
     * @brief Test the RequestQueue class and the different funcitonalities it has
     * 
     */
    static void testRequestQueue();

    /**
     * @brief Test the Server class and the different functionalities it has
     * 
     */
    static void testServer();

    /**
     * @brief Test the ServerGroup class and the different functionalities it has
     * 
     */
    static void testServerGroup();

    /**
     * @brief Simulate load balancing with an initial amount of requests, initial server amount, and clock cycles this load balancer will be running for
     * 
     * @details As the simulation runs, there will be new requests added to the request queue every 10 to 50 clock cycles.
     * 
     * @param initRequestAmount Initial amount of requests the request queue will start out with
     * @param initServerAmount Initial amount of servers the server group will start out with
     * @param clockCycles The amount of clock cycles the simulation will run for
     */
    static void simulateLoadBalancer(int initRequestAmount, int initServerAmount, int clockCycles);
};


#endif