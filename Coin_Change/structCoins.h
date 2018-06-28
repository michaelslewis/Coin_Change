/********************************************************************
 * Author: Patrick Mullaney
 * Date: 4/26/2017
 * CS325, Spring 2017
 * Description: Heaader file for struct which contains int value for
 * minimum number of coins needed to make change and a vector which 
 * for which each index holds the amount of a particular denomination.
 ********************************************************************/

#ifndef structCoins_h
#define structCoins_h
#include <vector>

using std::vector;

struct coins{
    vector <int> coin;
    int m;
};
#endif /* structCoins_h */
