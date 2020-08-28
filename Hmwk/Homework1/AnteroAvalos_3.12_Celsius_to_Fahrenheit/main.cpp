//Program that converts Celsius temperatures to Fahrenheit temperature
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//prototype
double convertToF(double c); //converts °C to °F


int main(int argc, char** argv) {
    //variables
    double celsius,
           fahrenheit;
    
    //get temp in F from user
    cout << "Enter the temperature you would like to convert (in C) :" ;
    cin >> celsius;
    
    //call function to convert the temp and assign to fahrenheit var
    fahrenheit = convertToF(celsius);
    
    //display result
    cout << "Your converted temperature is : " << fixed << setprecision(2) << fahrenheit << "F." << endl;
    
    return 0;
}

//definition

/**Converts a temp in °C to °F using the formula below:
 *              F=9/5C+32
 * @param c temp in celsius
 * @return double which is the value of temp in fahrenheit
 */
double convertToF(double c)
{
    return ((c * 9/5) + 32);
}