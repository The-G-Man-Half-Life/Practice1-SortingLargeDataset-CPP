//includes
#include "Performance.hpp"

//cronometer implementation
//Will be casted at the beggining of each method
void Timer::start() {
    startTime = std::chrono::high_resolution_clock::now();
}

//Will be casted at the beggining of each method
void Timer::stop() {
    endTime = std::chrono::high_resolution_clock::now();
}

/*This will do endTime - startTime which will calculate the amount 
of time taken for execution*/
double Timer::getDifferenceInMiliseconds() {
    //calculation and returnal of the value
    std::chrono::duration<double, std::milli> elapsed = endTime - startTime;
    return elapsed.count();
}

// Implementation of the memory calculus
// We take into account: data structure used + Number of elements + additional structures

void MemoryEstimator::printQuickSortMemory(int numElements) {
    // QuickSort uses a std::vector. 
    // Memory calculation involving the vector and the size of each element
    long long vectorBase = sizeof(std::vector<int>);
    long long elementsMemory = numElements * sizeof(int);
    long long recursionStack = (log2(numElements)) * 32; // ~32 bytes Due the recursivity 

    long long totalMemory = vectorBase + elementsMemory + recursionStack;

    std::cout << "Vector base: " << vectorBase << " bytes\n";
    std::cout << "Elementos (" << numElements << " strings): " << elementsMemory / 1024 << " KB\n";
    std::cout << "Stack recursivo (Aprox): " << recursionStack << " bytes\n";
    std::cout << "-> Total estimado: " << totalMemory / 1024 << " KB\n";
    std::cout << "========================================\n";
}

void MemoryEstimator::printHeapSortMemory(int numElements) {
    // HeapSort also uses a std::vector but its recursion is different
    long long vectorBase = sizeof(std::vector<int>);
    long long elementsMemory = numElements * sizeof(int);
    long long recursionStack = (log2(numElements)) * 32; // Max recursion of O(log N) at heapify 

    long long totalMemory = vectorBase + elementsMemory + recursionStack;

    std::cout << "Vector base: " << vectorBase << " bytes\n";
    std::cout << "Elementos (" << numElements << " strings): " << elementsMemory / 1024 << " KB\n";
    std::cout << "Stack recursivo de heapify: " << recursionStack << " bytes\n";
    std::cout << "-> Total estimado: " << totalMemory / 1024 << " KB\n";
    std::cout << "========================================\n";

}

void MemoryEstimator::printBalancedTreeMemory(int numElements) {
    // Memory of the Balanced tree
    long long nodeSize = sizeof(BalancedTree);
    long long allNodesMemory = numElements * nodeSize;
    
    long long finalVectorMemory = sizeof(std::vector<int>) + (numElements * sizeof(int));
    long long recursionStack = (log2(numElements)) * 32;

    long long totalMemory = allNodesMemory + finalVectorMemory + recursionStack;

    std::cout << "medida por nodo (sizeof): " << nodeSize << " bytes\n";
    std::cout << "Total de nodos (" << numElements << "): " << allNodesMemory / 1024 << " KB\n";
    std::cout << "Vector final: " << finalVectorMemory / 1024 << " KB\n";
    std::cout << "-> Total estimado: " << totalMemory / 1024 << " KB\n";
    std::cout << "========================================\n";

}