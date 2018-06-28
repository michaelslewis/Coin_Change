/********************************************************************************
 * Author: Matt Nutsch
 * Date: 4/27/2017
 * CS325, Spring 2017
 * Description: Implementation file for brute force algorithm to calculate the 
 * minimum number of coins needed to make change for three different algorithms.
 *******************************************************************************/
 
#include "changeSlow.hpp"
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
 
// Returns coins with for minimum number of coins to make i cents.
struct coins changeSlowi(vector<int> coin, int i, int K)
{
	vector<int> coin_copy; //the argument coin, but extended to 7 values
	
	struct coins output;
	output.m = 9999999;
	
	int loopMax[7] = { };  //array that tells us how many times to iterate; assume 7 maximum types of coins

	int workingTotal = 0; //stores the working total
	int workingCoinCount = 0; //stores the working count of coins
	
	//initialize loopMax and output
	for(int j = 0; j < 7; j++) 
	{
		loopMax[j] = 0;
		output.coin.push_back(0);
		if(j < coin.size())
		{
			coin_copy.push_back(coin[j]);
		}
		else
		{
			coin_copy.push_back(0);
		}
		//cout << coin_copy[j] << ", ";
	}
	//cout << "\n";
	
	//cout << "the length of coin is " << coin.size() << "\n";
	//cout << "the length of coin_copy is " << coin_copy.size() << "\n";
	
	
	//for each value, find the loop max (maximum iterations to check for that coin)
	for(int j = 0; j < 7; j++) 
    {
        if(coin_copy[j] == K) //If there is a K-cent coin, 
        {
            loopMax[j] = 1; //then that loopMax is 1
        }
		else if(coin_copy[j] > K) //If there is a coin whose value exceeds K, 
        {
            loopMax[j] = 0; //then ignore that coin
        }
		else 
		{
			if(coin_copy[j] > 0) //don't divide by zero
			{
				loopMax[j] = K / coin_copy[j]; //the loopMax for that coin is K / value
			}
			else
			{
				loopMax[j] = 0;
			}
		}
		//cout << "The loopMax of " << coin_copy[j] << " is " << loopMax[j] << "\n";
    }
	
	//assumes four coin values
	//first coin
	for(int j = 0; j <= loopMax[0]; j++) 
    {
		//second coin
		for(int k = 0; k <= loopMax[1]; k++) 
		{	
			//third coin
			for(int l = 0; l <= loopMax[2]; l++) 
			{	
				//fourth coin
				for(int m = 0; m <= loopMax[3]; m++) 
				{
					//fifth coin
					for(int n = 0; n <= loopMax[4]; n++) 
					{
						//sixth coin
						for(int o = 0; o <= loopMax[5]; o++) 
						{
							//seventh coin
							for(int p = 0; p <= loopMax[6]; p++) 
							{
								workingTotal = (coin_copy[0] * j) + (coin_copy[1] * k) + (coin_copy[2] * l) + (coin_copy[3] * m) + (coin_copy[4] * n) + (coin_copy[5] * o) + (coin_copy[6] * p);
								workingCoinCount = j + k + l + m + n + o + p;
								
								//if the total value = K
								if(workingTotal == K)
								{
									//cout << "matching total found\n";
									//cout << "quantities are: " << j << ", " << k << ", " << l << ", " << m << ", " << n << ", " << o << ", " << p << "\n";
									
									//if the count of coins < min
									if(workingCoinCount < output.m)
									{
										//cout << "new minimum found\n";
										
										output.m = workingCoinCount; //min = count of coins
								
										output.coin[0] = j;
										output.coin[1] = k;
										output.coin[2] = l;
										output.coin[3] = m;	
										output.coin[4] = n;	
										output.coin[5] = o;	
										output.coin[6] = p;	
									}
								}
							} //p
						} //o
					} //n
				} //m
			} //l
		} //k
	} //j
	
	//cout << "The min from  of changeSlowi is: " << output.m << "\n";
	//cout << output.coin[0] << ", " << output.coin[1] << ", " << output.coin[2] << ", " << output.coin[3] << "\n";
	return output;
	
}

// Returns coins for minimum number of coins to make K - i cents.
struct coins changeSlowKi(vector<int> coin, int i, int K)
{
	struct coins output;
	output.m = 0;
	
	output = changeSlowi(coin, (K - i), K);
	
	//cout << "The min from  of changeSlowKi is: " << output.m << "\n";
	//cout << output.coin[0] << ", " << output.coin[1] << ", " << output.coin[2] << ", " << output.coin[3] << "\n";
	
	return output;
}

// Returns coins that is the smaller of the two values
struct coins selectSmaller(struct coins min1, struct coins min2)
{
	struct coins output;
	output.m = 0;
	
	if(min1.m < min2.m)
	{
		output = min1;
	}
	else
	{
		output = min2;
	}
	
	return output;
}

// Returns coins that minimizes the number of coins needed
struct coins changeSlow(vector<int> coin, int amount, struct coins change)
{
	change.m = 99999999; //contains the minimum number of coins
	
	struct coins minFrom1;
	minFrom1.m = 999999999;
	struct coins minFrom2;
	minFrom2.m = 999999999;
	
	//initialize the output vector
	for(int i = 0; i < coin.size(); i++)
    {
        change.coin.push_back(0);
    }
	
	//check if there is a K-cent coin
	for(int i = 0; i < coin.size(); i++)
    {
		//cout << coin[i] << ", ";
        if(coin[i] == amount) //If there is a K-cent coin, 
        {
            change.m = 1; //then that one coin is the minimum
        }
    }
	//cout << "\n";
	
	/*
	//Otherwise, for each value i < K,
	for(int i = 0; i < amount; i++)
	{
		//1)	Find the minimum number of coins needed to make i cents
		minFrom1 = changeSlowi(coin, i, amount);
		
		//2)	Find the minimum number of coins needed to make K - i cents
		minFrom2 = changeSlowKi(coin, i, amount);
	}
	
	change = selectSmaller(minFrom1, minFrom2); //Choose the i that minimizes the sum of 1) and 2)
	*/
	
	change = changeSlowi(coin, amount, amount);
	
	return change;
}

