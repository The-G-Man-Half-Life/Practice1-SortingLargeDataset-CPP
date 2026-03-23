//include guards
#pragma once

//include of necesary elements
#include <vector>

class HeapSort
{
private:

    //methods in private as these will be used for the heap sort but should not be used externally

    /*This method takes care of obtaining the ubication of a left child given the vector 
    and the ubication of the father*/
    static const int obtainLeftChildUbication(std::vector<int>& intsVec, int fatherUbication);

    /*This method takes care of obtaining the ubication of a right child given the vector 
    and the ubication of the father*/
    static const int obtainRightChildUbication(std::vector<int>& intsVec, int fatherUbication);

    /*This method takes care of obtaining the ubication of a right child given the vector 
    and the ubication of the father*/
    static const int obtainFatherUbication(std::vector<int>& intsVec, int childUbication);

    /*Main method that takes care behind all the logic of switching values in the entire heap sort.
    It starts from the last element of the vector (intsVec) and by obtaining the "father" of that 
    last element of the vector (crrntChildUbication). The father will compare itself with its right
    and left children, in case these are in ubications less or equal to the lastSortedValUbication,
    This procces will obtain the ubication and value of the father, left and right child and by using
    the ubication of the left child it will go 1 position back obtaining the next left child of the 
    next trio(left child, right child, father) to review, which will be the new crrntChildUbication 
    too. After doing this process recursively until the element in the position 0 of the vectorm it 
    will swap the element in the position 0 with the lastSortedValUbication, which is a value that 
    will be kept through all of the iterations in each heapify execution, due that the element in the 
    top, after making all these swappings, will be the biggest number putting it at the end of the vector
    and then reducing the visible size of the vector by 1. Finally this method will cast maxHeapify
    and end the execution of the heapify by using a empty return*/
    static void heapify(std::vector<int>& intsVec,int crrntChildUbication, int lastSortedValUbication);

    /*This takes care of making the recursion process for when the entire vector (intsVec) is completely sorted
    this by using sortedLastPoint ,which is reduced by 1 from heapify, by receiving the ubication from which the 
    vector is not sorted casting heapify to keep sorting and reducing this value until it equals 0 in which case
    it will return the vector already sorted */
    static std::vector<int>& maxHeapify(std::vector<int>& intsVec,int sortedLastPoint);

public:

    // method public to execute the heap sort
    static void heapingSort(std::vector<int>&);
};

