/********************************************************************************
 * Author: Patrick Mullaney
 * Date: 4/26/2017
 * CS325, Spring 2017
 * Description: Implementation file for greedy algorithm to calculate the 
 * minimum number of coins needed to make change for three different algorithms.
 *******************************************************************************/

#include "changeGreedy.hpp"

int changeGreedy(vector<int> coin, int amount)
{
    int m = 0;
    
    for(int i = coin.size()-1; i >=0; i--)
    {
        while(coin[i] <= amount)
        {
            m++;
            amount -= coin[i];
        }
    }
    
    return m;
}

struct coins changeGreedy(vector<int> coin, int amount, struct coins change)
{
    change.m = 0;
    for(int i = 0; i < coin.size(); i++)
    {
        change.coin.push_back(0);
    }
    for(int i = coin.size()-1; i >=0; i--)
    {
        while(coin[i] <= amount)
        {
            change.m++;
            amount -= coin[i];
            change.coin[i]++;
        }
    }
    
    return change;
}