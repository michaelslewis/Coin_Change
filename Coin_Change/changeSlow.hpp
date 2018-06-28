/********************************************************************************
 * Author: Matt Nutsch
 * Date: 4/27/2017
 * CS325, Spring 2017
 * Description: Implementation file for brute force algorithm to calculate the 
 * minimum number of coins needed to make change for three different algorithms.
 *******************************************************************************/

#ifndef changeSlow_hpp
#define changeSlow_hpp

#include <stdio.h>
#include <vector>
#include "structCoins.h"

using std::vector;

// Returns coins for minimum number of coins to make i cents.
struct coins changeSlowi(vector<int> coin, int i, int K);

// Returns coins for minimum number of coins to make K - i cents.
struct coins changeSlowKi(vector<int> coin, int i, int K);

// Returns coins that is the smaller of the two values
struct coins selectSmaller(int min1, int min2);

// Returns coins for i that minimizes the number of coins needed
struct coins changeSlow(vector<int> coin, int amount, struct coins change);

#endif /* changeSlow_hpp */
