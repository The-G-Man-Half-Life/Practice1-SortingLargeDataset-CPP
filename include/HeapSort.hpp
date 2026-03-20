//include guards
#pragma once

//includes
#include <vector>

class HeapSort
{
private:
    //atributes

    //methods
    static const int obtainLeftChildUbication(std::vector<int>& intsVec, int fatherUbication){
        return 2*fatherUbication + 1;
    };
    static const int obtainRightChildUbication(std::vector<int>& intsVec, int fatherUbication){
        return 2*fatherUbication + 2;
    };
    static const int obtainFatherUbication(std::vector<int>& intsVec, int childUbication){
        return (childUbication - 1) / 2 ;
    };
    static void heapify(std::vector<int>& intsVec,int crrntChildUbication){
        //variables
        int fatherUbication;
        int fatherValue;
        int rightChildUbication;
        int rightChildVal;
        int leftChildUbication;
        int leftChildVal;
        int lastSortedValue;


        lastSortedValue = crrntChildUbication;
        
        if (crrntChildUbication == 0){
            
            maxHeapify(intsVec,lastSortedValue-1)
        }

        fatherUbication = obtainFatherUbication(intsVec, crrntChildUbication);
        fatherValue = intsVec.at(fatherUbication);
        rightChildUbication = obtainRightChildUbication(intsVec, fatherUbication);
        leftChildUbication = obtainLeftChildUbication(intsVec, fatherUbication);

        if (rightChildUbication < crrntChildUbication ){

            rightChildVal = intsVec.at(rightChildUbication);

            if (rightChildVal>fatherValue)
            {
                std::swap(intsVec[rightChildVal], intsVec[fatherValue]);
                fatherValue = rightChildVal;
            }
            
        }
        
        if (leftChildUbication < crrntChildUbication){   

            leftChildVal = intsVec.at(leftChildUbication);

            if (leftChildVal>fatherValue)
            {
                std::swap(intsVec[rightChildVal], intsVec[fatherValue]);
            }
        }

        heapify(intsVec,leftChildUbication-1);
        
    }

    static std::vector<int>& maxHeapify(std::vector<int>& intsVec,int sortedLastPoint){
        std::swap(intsVec[0], intsVec[sortedLastPoint - 1]);
    }

public:

    // methods
    static void heapingSort(std::vector)
};

