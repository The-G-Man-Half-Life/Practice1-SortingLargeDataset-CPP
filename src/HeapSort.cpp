//includes
#include "HeapSort.hpp"

//methods
/*Implementation of heapingSort which will receive the main vector and sort it
this will be accesible by other classes and methods allowing only the sorting by
this method without using the other unwanted ones*/
void HeapSort::heapingSort(std::vector<int>& intsVec){
    /*This is a usage of the private methods of the class which
    will take care of sorting by using the vector and the initial
    position to start sorting which is the last position*/
    HeapSort::maxHeapify(intsVec, intsVec.size()-1);
}