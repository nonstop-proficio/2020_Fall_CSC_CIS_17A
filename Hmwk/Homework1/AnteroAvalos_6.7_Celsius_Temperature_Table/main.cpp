/*The formula for converting a temperature from Fahrenheit to Celsius is
    C = (F -32) * 5/9;
where F is the Fahrenheit temperature and C is the Celsius temperature. Write a function
named celsius that accepts a Fahrenheit temperature as an argument. The function
should return the temperature, converted to Celsius. Demonstrate the function by
calling it in a loop that displays a table of the Fahrenheit temperatures 0 through 20
and their Celsius equivalents */

#include <iostream>
#include <iomanip>
using namespace std;

//function prototypes
double celsius(double fahrenheit); 

int main()
{
    //variables
    double convertedTemp,
           fahrenheit;

    //table header 
    const int fahrenheitWidth = 10,
              celsiusWidth = 10;
    const char filler = ' ';
    cout << "Temp. in F" << setw(10) << "" << "Temp. in C" << endl;
    
    //loop for table 0-20 °F degrees to °C
    for (fahrenheit=0; fahrenheit <= 20; fahrenheit++)
    {
        convertedTemp = celsius(fahrenheit);
        cout << fixed << setprecision(3) << setfill(filler) << right
                << setw(fahrenheitWidth) << fahrenheit << setw(10) << "" << setw(celsiusWidth) << convertedTemp << endl;
    }
    return 0;
}

/**
 * @brief converts fahrenheit to celsius 
 * 
 * @param fahrenheit temperature in fahrenheit
 * @return double temperature in celsius
 */
double celsius(double fahrenheit)
{
    double celsius;

    celsius = (fahrenheit -32) * 5/9;
    return celsius;
}