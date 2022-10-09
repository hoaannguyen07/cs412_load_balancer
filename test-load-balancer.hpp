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
     * @param int initRequestAmount 
     * @param int initServerAmount 
     * @param int clockCycles 
     */
    static void simulateLoadBalancer(int initRequestAmount, int initServerAmount, int clockCycles);
};


#endif