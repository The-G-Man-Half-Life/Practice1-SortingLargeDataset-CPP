#include <iostream>
#include "Utils.hpp"
#include "QuickSort.hpp"
#include "HeapSort.hpp"
#include "BalancedTree.hpp"
#include "Performance.hpp"

void executeQuickSort(std::vector<int>& unorganizedVector){
    //variable
    Timer timer;

    //execution
    timer.start();
    QuickSort::sortingQuick(unorganizedVector);
    timer.stop();

    //printing of information
    std::cout << "Quick sort Ejecutandose ..." << std::endl;
    std::cout << "Ordenamiento finalizado" << std::endl;
    std::cout << "Tiempo de ejecucion: " << timer.getDifferenceInMiliseconds() << std::endl;
    std::cout << "Uso de memoria estimado: ";
    MemoryEstimator::printQuickSortMemory(unorganizedVector.size());
}

void executeHeapSort(std::vector<int>& unorganizedVector){
    //variable
    Timer timer;

    //execution
    timer.start();
    HeapSort::heapingSort(unorganizedVector);
    timer.stop();

    //printing of information
    std::cout << "Heap sort Ejecutandose ..." << std::endl;
    std::cout << "Ordenamiento finalizado" << std::endl;
    std::cout << "Tiempo de ejecucion: " << timer.getDifferenceInMiliseconds() << std::endl;
    std::cout << "Uso de memoria estimado: ";
    MemoryEstimator::printHeapSortMemory(unorganizedVector.size());
}

void executeBalancedTree(std::vector<int>& unorganizedVector){
    //variable
    Timer timer;
    BalancedTree tree;
    std::vector<int> organizedList;

    //execution
    timer.start();
    //insert the Dataset in the tree first
    for (int number: unorganizedVector){
        tree.BalancedTree::insertNumber(number);
    }
    //calling the organizator method
    organizedList = tree.getInorder();
    timer.stop();

    //printing of information
    std::cout << "AVL tree Ejecutandose ..." << std::endl;
    std::cout << "Ordenamiento finalizado" << std::endl;
    std::cout << "Tiempo de ejecucion: " << timer.getDifferenceInMiliseconds() << std::endl;
    std::cout << "Uso de memoria estimado: ";
    MemoryEstimator::printHeapSortMemory(unorganizedVector.size());
}

int main(){
    // variables
    std::string fileUbication;
    std::vector<std::string> wordsVec;
    std::vector<int> intsVec;
    int wordsVecSize;
    BalancedTree tree;
    std::vector<std::string> organizedVectorByQuickSort;
    std::vector<std::string> organizedVectorByHeapSort;
    std::vector<std::string> organizedTreeVector;
    int option;
    bool flag = true;

    //caling the function to read the file
    fileUbication = "data/dataset.txt";
    wordsVec = Utils::readWordsFromFile(fileUbication);
    wordsVecSize = wordsVec.size();

    intsVec = Utils::convertWordsToInts(wordsVecSize);
    Utils::randomizeWordsOrd(intsVec,wordsVecSize);

    while (flag == true){
        option = Utils::showMenu();
        
        switch (option){
        case 1:
            executeQuickSort(intsVec);
            break;
        case 2:
            executeHeapSort(intsVec);
            break;
        case 3:
            executeBalancedTree(intsVec);
            break;
        case 4:
            std::cout << "Adios" << std::endl;
            flag = false;
            break;
        default:
            break;
        }
    }
}
