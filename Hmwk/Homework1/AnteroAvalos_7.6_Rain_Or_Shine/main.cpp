#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

//Global constants for the multidimensional array size declarators-----
const int MONTHS = 3,
          DAYS = 30;

//Function Prototypes-----
void wrtFile(string); //Write weather data to file 
void rdFileToArr(char [][DAYS], string); //Reads contents of file and stores them in 2D array
void assgnMonthData(string ,char [],const char[][DAYS]); //Assign corresponding weather data to each month
void dispSummerStats(const char [][DAYS]); //Display # of R, C, and S days in summer array
void dispMonthlyStats(string , const char[]); //Display # of R, C, and S days in month array
void displayHighestRainy(const char [][DAYS]); //Display which month had the highest # of rainy days

//Main STARTS here-----
int main(){
//Set the random seed here
srand(static_cast<unsigned int>(time(0)));
//Variable declarations
string fileName = "RainOrShine.txt";                  //File Name
string month_names[MONTHS] = {"June", "July", "August"};   //Month names array
char summer_weather[MONTHS][DAYS];                    //Array for conditions all summer (90 days, excludes 31st day)
char june_weather[DAYS],                              //Array for conditions in June
     july_weather[DAYS],                              //Array for conditions in July
     august_weather[DAYS];                            //Array for conditions in August
//Create RainOrShine.txt file
wrtFile(fileName);
//Write contents of file to weather conditions arr (only works with 2D arrays)
rdFileToArr(summer_weather, fileName); 
//Assign corresponding weather data to each month
assgnMonthData(month_names[0], june_weather, summer_weather);
assgnMonthData(month_names[1], july_weather, summer_weather);
assgnMonthData(month_names[2], august_weather, summer_weather);

//User friendly info:
cout << "These were the numbers recorded over the summer: " << endl;
//display monthly stats 
dispMonthlyStats(month_names[0], june_weather);
dispMonthlyStats(month_names[1], july_weather);
dispMonthlyStats(month_names[2], august_weather);
//display summer stats
dispSummerStats(summer_weather);
//display which month had the highest # of rainy days
displayHighestRainy(summer_weather);
return 0;
}
//Main ENDS here-----

//Function Definitions -----
/**
 * @brief  Writes weather data to file 
 * 
 * @param fileName a string which holds the name of the file
 */
void wrtFile(string fileName){
    const char w_types [3] = {'R', 'C', 'S'}; // Types of weather to write 
    const int daysRecorded = 90; //Days to write info on file

    //Random number between 0-2 to write a random weather type from w_types array 
    int randWT;
    
    //Open file
    ofstream outputFile;
    outputFile.open(fileName);
    //write weather data to file
    for(int month = 0; month < MONTHS; month++){
        for(int day = 0; day < DAYS; day++){
            randWT = (rand() % (2 - 0 + 1)) + 0; 
            outputFile << w_types[randWT]; //randWT is a random int between 0-2
        }
        outputFile << endl;
    }         
    //close file
    outputFile.close();
}

/**
 * @brief Reads contents of file and stores them in 2D array
 * 
 * @param arr Array that file contents are being stored in 
 * @param fileName Name of the file that will be read
 */
void rdFileToArr(char arr[][DAYS], string fileN){ 
    ifstream inputFile;
    inputFile.open(fileN);
    for (int row = 0; row < MONTHS; row++){
        for (int col = 0; col < DAYS; col++){
            inputFile >> arr[row][col];
        }
    }
    inputFile.close();
}

/**
 * @brief Assign corresponding weather data to each month
 * 
 * @param month string, name of the month
 * @param monthArr name of a one dimensional array that contains weather data for that month.
 * @param summerArr 2d array that contains the data which will be assigned
 */
void assgnMonthData(string month, char monthArr[], const char summerArr[][DAYS]){
    //Used to iterate within designated parts of the summer array
    int selectedM = 0; //designates the row I want to get the values from

    if(month == "June")
        selectedM = 1;
    if(month == "July")
        selectedM = 2;
    if(month == "August")
        selectedM = 3;

    for(int month = 0; month < selectedM; month++){
        for(int day = 0; day < DAYS; day++){
            monthArr[day] = summerArr[month][day];
        }
    }
}

/**
 * @brief Display # of R, C, and S days in summer array
 * 
 * @param summerArr name of 2d array of chars containing the weather data
 */
void dispSummerStats(const char summerArr[][DAYS]){
    int totalRainy = 0,
        totalCloudy = 0,
        totalSunny = 0;

    for(int month = 0; month < MONTHS; month++){
        for(int day = 0; day < DAYS; day++){
            if(summerArr[month][day] == 'R') {totalRainy++;}
        }
    }
    for(int month = 0; month < MONTHS; month++){
        for(int day = 0; day < DAYS; day++){            
            if(summerArr[month][day] == 'C') {totalCloudy++;}            
        }
    }
    for(int month = 0; month < MONTHS; month++){
        for(int day = 0; day < DAYS; day++){
            if(summerArr[month][day] == 'S') {totalSunny++;}
        }
    }
    cout << endl;
    cout << "There was a total of " << totalRainy << " rainy days this summer." << endl;
    cout << "There was a total of " << totalCloudy << " cloudy days this summer." << endl;
    cout << "There was a total of " << totalSunny << " sunny days this summer." << endl;
}

/**
 * @brief Display # of R, C, and S days in month array
 * 
 * @param month Name of the month, string 
 * @param monthArr name of 1d array, contains weather data for that month
 */
void dispMonthlyStats(string month, const char monthArr[]){
    int totalRainy = 0,
        totalCloudy = 0,
        totalSunny = 0;

    for(int i = 0; i < DAYS; i++){
        if(monthArr[i] == 'R') {totalRainy++;}
        if(monthArr[i] == 'C') {totalCloudy++;}
        if(monthArr[i] == 'S') {totalSunny++;}
    }
    cout << endl;
    cout << month << " had : " << "\n"
         << totalRainy << " rainy days.\n" 
         << totalCloudy << " cloudy days.\n" 
         << totalSunny << " sunny days.\n";
}

/**
 * @brief Display which month had the highest # of rainy days
 * 
 * @param summerArr 2d array containing weather data for the summer
 */
void displayHighestRainy(const char summerArr[][DAYS]){
    int junRainy = 0,
        julRainy = 0,
        augRainy = 0;
    for(int month = 0; month < MONTHS; month++){
        for(int day = 0; day < DAYS; day++){
            if(summerArr[0][day] == 'R') {junRainy++;}
            if(summerArr[01][day] == 'C') {julRainy++;}
            if(summerArr[02][day] == 'S') {augRainy++;}
        }
    }
    if(junRainy > julRainy && junRainy > augRainy){
        cout << "\nJune had the highest amount of rainy days." << endl;
    }else if(julRainy > junRainy && julRainy > augRainy){
        cout << "\nJuly had the highest amount of rainy days." << endl;
    }else{
        cout << "\nAugust had the highest amount of rainy days." << endl;
    }
}
