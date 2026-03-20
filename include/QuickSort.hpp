//include guards
#pragma once

//importation of required elements
#include <vector>
#include <string>


class QuickSort
{
private:
    //atributes

public:
    //constructor

    //methods
    static std::vector<int> SortingQuick(std::vector<int>& intsVec, int start, int end);
    static int partitionate(std::vector<int>& intsVec, int start, int end);

};

