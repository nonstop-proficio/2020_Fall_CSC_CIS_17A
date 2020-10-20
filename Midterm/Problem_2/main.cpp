/*
2)  Develop an application using an array of structures that will 
determine the gross pay for any number of employees input. The company pays 
"straight-time" for the first 40 hours worked, double time for 
all hours worked in excess of 40 hours but less than 50 hours, 
and triple time for any hours worked over 50 hours.

The program should be able to loop and input the employee's name, 
hours worked, and the rate of pay.  Once this has been done then output
this information including the gross pay in the form of a paycheck.
The process starts all over 
again until you input an invalid rate of pay or hours worked.  This
means a negative rate of pay or negative number of hours worked is
not acceptable.

Print it out like an actual paycheck with English
language representing the check amount.
Printout like a company Paycheck with format:
     Company
     Address
     Name:	Amount: numerical
     Amount:    English of numerical value
     Signature Line:
 */

/* 
 * File:   main.cpp
 * Author: Antero
 *
 * Created on October 19, 2020
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

//User Libraries
#include "Employee.h"

//Function Prototypes
int numEmpl();          //Gets number of employees for payroll 
Employee * fillAry(int);   //Fill struct array with payroll data

//--------------------------MAIN starts here--------------------
int main(int argc, char** argv) {
    int size = numEmpl();

    Employee * payroll;

    payroll = fillAry(size);


    return 0;
}
//--------------------------MAIN ends here---------------------
int numEmpl(){
    int nWrkrs;
    
    cout << "Enter the number of employees you need checks for: ";
    cin >> nWrkrs;

    return nWrkrs;
}


Employee * fillAry(int arySize){
    Employee * payroll = new Employee[arySize];

    for (int i = 0; i < arySize; i++)
    {
        cin.ignore();
        cout << "Enter employee's name: ";
        getline(cin, payroll[i].name);
        cout << "Hours worked: ";
        cin >> payroll[i].workHrs;
        cout << "Employee's pay rate: ";
        cin >> payroll[i].payRate;
    }
    
    return payroll;
}