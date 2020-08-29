/*
  Population
Write a program that will predict the size of a population of organisms. The program
should ask the user for the starting number of organisms, their average daily population
increase (as a percentage), and the number of days they will multiply. A loop
should display the size of the population for each day.
Input Validation: Do not accept a number less than 2 for the starting size of the population.
Do not accept a negative number for average daily population increase. Do not
accept a number less than 1 for the number of days they will multiply.
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char** argv) 
{
    int startingPop,
        daysMult,
        newPop,
        increase;
    
    double avgPopIncrease;    
    
    //get starting # of organisms
    cout << "\nProvide starting number of organisms: ";
    cin >> startingPop;
    cin.ignore();
    //validate population input
    if (startingPop < 2)
    {
        cout << "Population must be greater than 2 organisms!!\n";
    }
    else
    {
        //get average population increase
        cout << "\nEnter the average daily population increase percentage.";
        cout << "\nAny fractional percentage will be rounded up(e.g: 0.5 = 1): ";
        cin >> avgPopIncrease;
        cin.ignore();
        //validate average daily population increase input
        if (avgPopIncrease < 0)
        {
            cout << "Population increase must be greater than 0!!\n";
        }
        else
        {
            //get number of days organisms will multiply
            cout << "\nEnter the number of days you want to calculate: ";
            cin >> daysMult;
            cin.ignore();
            //validate number of days input
            if (daysMult < 1)
            {
                cout << "Number of days must be greater than 0!!\n" << endl;
            }
            else
            {
                //table header
                const int dayWidth = 6,
                          popWidth = 12,
                          incWidth = 14;
                const char filler = ' ';
                cout << setfill(filler) << setw(dayWidth) << "Days" 
                        << setw(popWidth) << "Population" 
                        << setw(incWidth) << "Increase" << endl;    
                //loop for table 
                int temp;
                for (int i = 1; i <= daysMult; i++)
                {
                    increase = ceil((avgPopIncrease / 100)* startingPop);
                    newPop = startingPop + increase;
                    cout << right << setfill(filler)
                            << setw(dayWidth) << i 
                            << setw(popWidth) << newPop 
                            << setw(incWidth) << increase << setw(0) << " organisms" << endl;
                    temp = newPop;
                    startingPop = temp; 
                }
            }
        }            
    }
    cout << "Goodbye!";
    return 0;
}

