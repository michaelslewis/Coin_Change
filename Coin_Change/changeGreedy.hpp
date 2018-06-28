/*************************************************************************
 * Author: Patrick Mullaney
 * Date: 4/26/2017
 * CS325, Spring 2017
 * Description: Header file for greedy algorithm to calculate the minimum 
 * number of coins needed to make change for three different algorithms.
 ************************************************************************/

#ifndef changeGreedy_hpp
#define changeGreedy_hpp

#include <stdio.h>
#include <vector>
#include "structCoins.h"

using std::vector;
// Returns only an int for minimum number of coins.
int changeGreedy(vector<int> coin, int amount);
// Returns struct containing minimum number of coins and denomination of coins.
struct coins changeGreedy(vector<int> coin, int amount, struct coins change);

#endif /* changeGreedy_hpp */
