//
//  changeDP.cpp
//  Project2
//
//  Created by Patrick Mullaney on 4/27/17.
//  Copyright © 2017 Patrick Mullaney. All rights reserved.
//

#include "changeDP.hpp"
#include <iostream>

struct coins changeDP(vector<int> coin, int amount, struct coins change)
{
   // changdp(amount) = std::min{changedp(amount-coin)+1}
   /* for(int i = 0; i < coin.size(); i++)
    {
        change = changeDP(amount-coin[i]);
        
        m = std::min{change.m = changeDP(amount-coin[i])+1};
    } */
    
    
    for(int i = 0; i < coin.size(); i++)
    {
        change.coin.push_back(0);
    }
    
    int table[amount+1];  // Memoization table for minimum coin values.
    int coinsUsed[amount+1]; // Tablle track coins used.
   
    // Base
    table[0] = 0;
    coinsUsed[0] = 0;
    
    // Initialize rest of table to arbitrary large number.
    for(int i = 1; i <= amount; i++)
    {
        table[i] = 9999;
        coinsUsed[i] = -1;
    }

    for(int i = 1; i <= amount; i++)
    {
        
        for(int j = 0; j < coin.size(); j++)
        {
            if(coin[j] <= i) // If coin j is less than amount i.
            {
                int min = table[i-coin[j]]; // min = table i minus that denomination.
          
                if((min != 9999) && (min + 1) < table[i]) // If min less than current min, update new min.
                {
                    table[i] = min + 1; // New min is min + 1 as we have used one more coin.
                    coinsUsed[i] = j;  // Assign index j of denomination used to coinUsed[i].
                }
            }
        }
    }
    
    /*  Output of coinsUsed values for testing.
    std::cout << "coins used: ";
    for(int i = amount; i >= 0; i--)
    {
        std::cout << coinsUsed[i] << " ";
    }
    std::cout<<  std::endl; */
    
    change.m = table[amount];
    
    /* Output of table values for testing.
    std::cout << "table: ";
    for(int i = amount; i >= 0; i--)
    {
        std::cout << table[i] << " ";
    }
        std::cout << std::endl; */
    
    // Denomination amounts = amount at that table.
    for(int i = change.m-1; i >= 0; i--)
    {
        change.coin[coinsUsed[amount]]++; // Increment coins based on value of coinsUsed table.
        amount -= coin[coinsUsed[amount]]; // Decrement amount.
    }
    
    return change;
}
