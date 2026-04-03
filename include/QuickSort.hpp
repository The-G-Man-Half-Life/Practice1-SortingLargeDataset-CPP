//include guards
#pragma once

//include of necessary elements
#include <vector>

class QuickSort
{
private:
    //private methods that will take care of the sorting method by using recursion

    /*SortingQuickLR (SortingQuickLeftRight) takes care of receiving the vector and the part where it will sort from
    (start) until a certain point (end). It will do that recursively creating mini imaginary vectors inside the vector
    until the sorting made by partitionate brings us to start == end because it means that the sorting in the vector 
    would have been completed already. We use something called pivot which will be the center(we take it always at 
    the end of each vector) of the algorithm as it will compare its value with every element put in the left
    in case is less or equal to itself, but if is bigger we put it on the right side once this organization is made 
    we leave that pivot and make the imaginary vector in each side where the left will begin from the start of the 
    original vector and 1 position back of the pivot we left alone and the right will begin 1 position after the pivot 
    we left alone and will end at the end of the original vector where each end position of each imaginary vector(Left
    and Right) will turn into its own pivot repeating this process recursively until there is no left side or right side
    meaning all of the items are organized. The organization of each imaginary vector that will be created will always 
    begin from the left and then will be sorted the right side*/
    static std::vector<int> sortingQuickLR(std::vector<int>& intsVec, int start, int end);
    
    /*method that rearranges the vector and the mini imaginary vectors we pass to it
    and returns the pivot position so the new imaginary vectors can be made having as 
    the center that pivot which is already part of the organized vector */ 
    static int partitionate(std::vector<int>& intsVec, int start, int end);
public:
    /*method that will take care of receiving the vector
    and passing the required parameters to the private methods
    which will apply the recursion and sorting process*/
    static void sortingQuick(std::vector<int>& intsVec);
};

