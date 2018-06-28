/********************************************************************
 * Author: Patrick Mullaney
 * Date: 4/26/2017
 * CS325, Spring 2017
 * Description: Main driver for program that tests the minimum number
 * of coins needed to make change for three different algorithms.
 * Note: Edited 4-30-2017 by Matt Nutsch
 ********************************************************************/

#include <iostream>
#include <chrono> //for measuring time elapsed

#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
#include <cstdlib>
#include "structCoins.h"
#include "changeGreedy.hpp"
#include "changeSlow.hpp"
#include "changeDP.hpp"

#include <iomanip>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

//using std::chrono; //for measuring time elapsed

int main(int argc, const char * argv[]) 
{
    std::ifstream inputFile;
    std::ofstream outputFile;
    
    /* Need to update to take arguments from command line */
    const char* fileName = "amount.txt";
    string change = "change.txt";
    if(argc > 1)
    {
        fileName = argv[1];
        string fileN(fileName);
        outputFile.open(fileN + change);
    }
    
    string readFile(fileName);
    inputFile.open(readFile + ".txt");
    
    string line;
    string number;
    int amount;
    
    if(inputFile)
    {
        // Read input line by line.
        while(getline(inputFile, line))
        {
            std::stringstream stream(line);
            vector<int> numbers((std::istream_iterator<int>(stream)),
                                (std::istream_iterator<int>()));
            // Get amount.
            getline(inputFile, number);
            amount = std::stoi(number);
            
            // Test amounts.
            vector<int> c = {1,2,4,8};
            vector<int> d = {1,3,7,12};
			vector<int> f = {1,2,6,12,24,48,60};
			vector<int> g = {1,5,10,25,50};
			vector<int> h = {1,6,13,37,150};
            
            // Algorithm 1
            struct coins slow;
			std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
            slow = changeSlow(numbers, amount, slow);
            
			std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
            
            // Output to file:
            outputFile << "Algorithm changeslow:\n";
            for(int i = 0; i < numbers.size(); i++) // Output array of denominations to file.
            {
                outputFile << numbers[i] << " ";
            }
            outputFile << "\n";
            for(int i = 0; i < numbers.size(); i++) // Output coins used to file.
            {
                
                if(numbers[i] < 10)
                {
                    outputFile << slow.coin[i] << " ";
                }
                else if(numbers[i] < 100)
                {
                    outputFile << slow.coin[i] << "  ";
                }
                else
                    outputFile << slow.coin[i] << "   ";
                
            }
            outputFile << "\n";
            outputFile << slow.m << "\n";   // Output amount of minimum coins to file.
            
			cout << "Brute Force m: " << slow.m << endl;
            for(int i = 0; i < numbers.size(); i++)
            {
                cout << std::setw(1) << std::left;
                cout << numbers[i] << " ";
            }
            cout << endl;
            for(int i = 0; i < numbers.size(); i++)
            {
                if(numbers[i] < 10)
                {
                    cout << slow.coin[i] << " ";
                }
                else if(numbers[i] < 100)
                {
                    cout << slow.coin[i] << "  ";
                }
                else
                    cout << slow.coin[i] << "   ";
            }
            cout << endl; 
            cout << "The time elapsed was " << duration << endl << endl;
			
			
            // Algorithm 2
            struct coins greedy;
			t1 = std::chrono::high_resolution_clock::now();
            greedy = changeGreedy(numbers, amount, greedy);
			t2 = std::chrono::high_resolution_clock::now();
			duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
            
            // Output to file:
            outputFile << "Algorithm changegreedy:\n";
            for(int i = 0; i < numbers.size(); i++) // Output array of denonminations to file.
            {
                outputFile << numbers[i] << " ";
            }
            outputFile << "\n";
            for(int i = 0; i < greedy.coin.size(); i++) // Output coins used to file.
            {
                if(numbers[i] < 10)
                {
                    outputFile << greedy.coin[i] << " ";
                }
                else if(numbers[i] < 100)
                {
                    outputFile << greedy.coin[i] << "  ";
                }
                else
                    outputFile << greedy.coin[i] << "   ";
            }
            outputFile << "\n";
            outputFile << greedy.m << "\n";   // Output amount of minimum coins to file.
            
            cout << "Greedy m: " << greedy.m << endl;
            for(int i = 0; i < greedy.coin.size(); i++)
            {
                cout << greedy.coin[i] << " ";
            }
            cout << endl;
			cout << "The time elapsed was " << duration << endl << endl;
			
            // Algorithm 3
            struct coins dp;
			t1 = std::chrono::high_resolution_clock::now();
            dp = changeDP(numbers, amount, dp);
			t2 = std::chrono::high_resolution_clock::now();
			duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
            
            // Output to file:
            outputFile << "Algorithm changedp:\n";
            for(int i = 0; i < numbers.size(); i++) // Output array of denominations to file.
            {
                outputFile << numbers[i] << " ";
            }
            outputFile << "\n";
            for(int i = 0; i < dp.coin.size(); i++) // Output coins used to file.
            {
                if(numbers[i] < 10)
                {
                    outputFile << dp.coin[i] << " ";
                }
                else if(numbers[i] < 100)
                {
                    outputFile << dp.coin[i] << "  ";
                }
                else
                    outputFile << dp.coin[i] << "   ";
            }
            outputFile << "\n";
            outputFile << dp.m << "\n";   // Output amount of minimum coins to file.
            
            
            cout << "Dynamic Programming m: " << dp.m << endl;
            for(int i = 0; i < dp.coin.size(); i++)
            {
                cout << dp.coin[i] << " ";
            }
            cout << endl;
			cout << "The time elapsed was " << duration << endl << endl;
        }
    }
    else
        cout << "File not found." << endl;
    
    return 0;
}

 /* User runs the programs on the command-line, specifying a file ([input filename].txt) in which the first line contains the array V, formatted as 1 5 10 25, denominations in increasing order.
The next line contains one integer value for which we must make change.

Program output should be written to a file named [input filename]change.txt where [input filename].txt is the input filename, and should be formatted with the name of the algorithm used, the denominations,  the change result and the minimum number of coins m, per line.  For example
               
               Amount.txt:
               1 2 5
               10
               1 3 7 26
               22
               Amountchange.txt:
               Algorithm changeSlow:
               1 2 5
               0 0 2
               2
               1 3 7 26
               1 0 3 0
               4
*/