/*An amateur meteorologist wants to keep track of weather conditions during the
past year’s three-month summer season and has designated each day as either rainy
(‘R’), cloudy (‘C’), or sunny (‘S’). Write a program that stores this information in a
3 × 30 array of characters, where the row indicates the month (0 = June, 1 = July,
2 = August) and the column indicates the day of the month. Note that data are not
being collected for the 31st of any month. The program should begin by reading the
weather data in from a file. Then it should create a report that displays, for each
month and for the whole three-month period, how many days were rainy, how many
were cloudy, and how many were sunny. It should also report which of the three
months had the largest number of rainy days. Data for the program can be found in
the RainOrShine.txt file.*/

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
//constants for array declarations
const int ROWS = 3,
          COLUMNS = 30;

//array declarations, global access
string weather_types[ROWS] =  {"Rainy", "Cloudy", "Sunny"};
string months[ROWS]             =  {"June", "July", "August"};
char weather_day_names[ROWS]    =  {'R', 'C', 'S'};

//function prototypes
void readFileTo(char[][COLUMNS], string);
void displayDays(const char[][COLUMNS], int);
void displayMonths(const char[][COLUMNS], int);
void displayHighest(const char[][COLUMNS]);

//main
int main()
{
    char weather_conditions[ROWS][COLUMNS];

    readFileTo(weather_conditions, "RainOrShine.txt");

    for (int letter = 0; letter < ROWS; letter++)
        displayDays(weather_conditions, letter);
    

    for (int i = 0; i < ROWS; i++)
        displayMonths(weather_conditions, i);
    

    displayHighest(weather_conditions);

    cout << endl;

    return 0;
}

//function definitions
void readFileTo(char array[][COLUMNS], string fileName)
{
    ifstream inputFile;

    inputFile.open(fileName);

    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLUMNS; col++)
        
            inputFile >> array[row][col];
        
    }
    
    inputFile.close();
}

void displayDays(const char array[][COLUMNS], int i)
{
    int total;
    for (int row = 0; row < ROWS; row++)
    {
        total = 0;
        for (int col = 0; col < COLUMNS; col++)
        
            if (array[row][col] == weather_day_names[i])
            { total++; }
        
        cout << "Total "
             << weather_types[i]
             << " days for "
             << months[row]
             << " = "
             << total
             << endl;
    }
    cout << endl;
}

void displayMonths(const char array[][COLUMNS], int i)
{
    int total = 0;
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLUMNS; col++)        
            if (array[row][col] == weather_day_names[i])
            { total++; }
    }        
            cout << "Total "
                 << weather_types[i]
                 << " days for all months = "
                 << total
                 << endl;
        
    
}


void displayHighest(const char array[][COLUMNS])
{
    int sum;
    int total_rainy_days[ROWS];
    
    for (int row = 0; row < ROWS; row++)
    {
        sum = 0;
        for (int col = 0; col < COLUMNS; col++)
            if (array[row][col] == 'R') { sum++; }
            
        total_rainy_days[row] = sum;
    }

    cout << endl;


    int highest_rainy_day = total_rainy_days[0];
    string highest_rainy_day_name = months[0];

    for(int i = 1; i < ROWS; i++)
    {
        if(total_rainy_days[i] > highest_rainy_day)
        {
            highest_rainy_day = total_rainy_days[i];
            highest_rainy_day_name = months[i];
        } 
        else if(total_rainy_days[i] == highest_rainy_day)
        {
            highest_rainy_day = total_rainy_days[i];
            highest_rainy_day_name += ", ";
            highest_rainy_day_name += months[i];
        }
            
    }

    cout << highest_rainy_day_name
         << " had the highest rainy days, "
         << "with "
         << highest_rainy_day
         << " days."
         << endl;
}
