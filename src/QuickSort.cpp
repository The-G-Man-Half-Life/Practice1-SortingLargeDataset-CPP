//#includes
#include "QuickSort.hpp"
#include <vector>
#include <iostream>

//methods
    //method that will be used for recursivity
    std::vector<int> QuickSort::SortingQuick(std::vector<int>& intsVec, int start, int end){
        //variables
        int pivot;

        //when start equals end (base case) the function ends
        if (start < end){        
            
            //finding the pivot
            pivot = partitionate(intsVec, start, end);

            //recursivity for left
            SortingQuick(intsVec, start, pivot-1);
            //recursivity for right
            SortingQuick(intsVec, pivot + 1, end);
        }

        return intsVec;
    }
    
    //method that rearrangeds the vector and returns the pivot position 
    int QuickSort::partitionate(std::vector<int>& intsVec, int start, int end){
        //variables
        int i;
        int j;
        int pivotValue;

        //defining variables
        i = start - 1;
        j = start;
        pivotValue = intsVec.at(end);
        
        //cycle to move around the mini elements
        for(; j <= end ; j++)
        {
            //switching positions only if the element at j is less or equal compared to the element at the end
            if (intsVec.at(j) <= pivotValue){
                i++;
                std::swap(intsVec[i], intsVec[j]);
            }
        }

         return i;

    }