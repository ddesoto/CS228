/*
 11/29/2015
 CS 228 A
 Program 6
 Dominic DeSoto
 
 Sources: 
 * Professor Hansen's class lectures, notes, and videos
 * Textbook, Data Structures and Other Objects Using C++ by Main and Savitch

 */

// BinarySearch.cpp

#include "BinarySearch.h"
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

binarySearch::binarySearch() { // Initialize class variables within constuctor;
    arrayLen = 0;   // The length of the given array will be zero until another
                    // value is passed in from the main function;
    target = 0; // Target integer is zero until another value is passed from the
                // main function;
}

binarySearch::~binarySearch() {
    // No dynamically-allocated memory to clean up, so destructor remains empty;
}

int binarySearch::search(int a[], unsigned int arrayLen, int target, bool sorted) {
    // This is the function where all the magic happens;
    if (arrayLen == 0)  // If the array length is zero,
        return -1;  // the array is empty and we have a problem;

    if (sorted == false) {  // If the array is not sorted, a linear search must 
                            // be used to find the target integer;
        for (int i = 0; i < arrayLen; i++) {    // For-loop traverses each
                                                // element in the array;
            if (a[i] == target) // If the given integer in the array is equal to
                                // the target, we've found the bugger;
                return i;   // Return the position of the given integer in the 
                            // array;
        }
        return -1;  // If the target integer was not found in the array, return -1;
    }

    else {  // Otherwise, it is inferred that the array is sorted and a binary 
            // search will be conducted for the target integer;
        unsigned int lowerIndex = 0;    // Temp variable for lower end of index;
        unsigned int middleIndex = 0;   // Temp variable for middle of index;
        unsigned int upperIndex = arrayLen; // Temp variable for upper end of 
                                    // index, set by default to array's length;

        middleIndex = (lowerIndex + upperIndex) / 2;
        // Middle of index can be located by adding lower and upper ends of 
        // index together and dividing by two;

        while ((target != a[middleIndex]) && (lowerIndex <= upperIndex)) {
            // The idea for this parameter was found at 
            // http://mathbits.com/MathBits/CompSci/Arrays/Binary.htm;
            // Execute the following code until the target integer matches the  
            // value of the middle index AND the lower index is less than or 
            // equal to the upper index;  
            if (a[middleIndex] > target) {
                // If the given value of the middle index is greater than the 
                // target integer,
                upperIndex = middleIndex - 1;   // shift middle index to the 
                                                // lower end of the array;
            } else {
                // Otherwise, the given value of the middle index is less than 
                // the target integer;
                lowerIndex = middleIndex + 1;   // Shift middle index to the 
                                                // higher end of the array;
            }
            middleIndex = (lowerIndex + upperIndex) / 2;    // Update the middle
                // index based on above if-else statements;
        }       // Check if the while-loop parameters have been satisfied with
                // this middle index;
        if (lowerIndex <= upperIndex)   // If the lower index is less than or 
                // equal to the upper index,
            return middleIndex; // return the middle index value obtained from 
                // while-loop;
        else    //Otherwise, 
            return -1;  // the target integer is not found in the array;
    }
}