//include guards
#pragma once

//include of necessary elements
#include <chrono>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

// Clase to seize the time of execution
class Timer {
private:
    //Atributes
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> endTime;

public:
    //Methods
    void start();
    void stop();
    //Method to obtain the difference
    double getDifferenceInMiliseconds();
};

// Class implemented to seize the memory usage
class MemoryEstimator {
public:
    // Replication of BalancedTree to obtain its data
    struct BalancedTree {
        int content;
        void* left;
        void* right;
        int height;
    };

    // stimation functions
    static void printQuickSortMemory(int numElements);
    static void printHeapSortMemory(int numElements);
    static void printBalancedTreeMemory(int numElements);
};