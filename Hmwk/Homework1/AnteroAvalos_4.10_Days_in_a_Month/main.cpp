//Program shows haw many days where in a particular month
//Only works for years after 1582, when the current Gregorian calendar was created
//Also limited the range of years to 7.8 million, expected extinction of human race
//according to J. Richard Gott's formulation of the controversial Doomsday argument

//input validation needs work

#include <iostream>
#include <iomanip>
using namespace std;

//function prototypes
bool isDivisible (int num1, int num2);

int main()
{
    //Variables
    const int   GREGORIAN_CAL_START_YEAR = 1582,
                ESTIMATED_HUMAN_EXTINCTION = 7800000;
    int month, year;

    bool leave = false; //let user exit program
    
    do
    {
        //get month from user
        cout << "Enter a month (1-12), enter 0 to Exit: ";
        cin >> month;
        cin.ignore();
    
        //get year from user
        cout << "Enter a year (1582 to 7.8 Milli on): ";
        cin >> year;        
        cin.ignore();
        
        if(year > GREGORIAN_CAL_START_YEAR && year <= ESTIMATED_HUMAN_EXTINCTION) //check that year is in range
        {
            string monthLength = "";             

            switch (month)
            {
                case 1:
                    monthLength = "31 days";
                    cout << monthLength << endl;
                    break;
                case 2:
                    if (isDivisible(year, 100) == true && (isDivisible(year, 400) == true))
                    {
                        monthLength = "29 days";
                        cout << monthLength << endl;
                    }
                    else if (isDivisible(year, 100) == false && (isDivisible(year, 4) == true))
                    {
                        monthLength = "29 days";
                        cout << monthLength << endl;
                    }
                    else
                    {
                        monthLength = "28 days";
                        cout << monthLength << endl;
                    }
                    break;
                case 3:
                    monthLength = "31 days";
                    cout << monthLength << endl;
                    break;
                case 4:
                    monthLength = "30 days";
                    cout << monthLength << endl;
                    break;
                case 5:
                    monthLength = "31 days";
                    cout << monthLength << endl;
                    break;
                case 6:
                    monthLength = "31 days";
                    cout << monthLength << endl;
                    break;
                case 7:
                    monthLength = "31 days";
                    cout << monthLength << endl;
                    break;
                case 8:
                    monthLength = "31 days";
                    cout << monthLength << endl;
                    break;
                case 9:
                    monthLength = "30 days";
                    cout << monthLength << endl;
                    break;
                case 10:
                    monthLength = "31 days";
                    cout << monthLength << endl;
                    break;
                case 11:
                    monthLength = "30 days";
                    cout << monthLength << endl;
                    break;
                case 12:
                    monthLength = "31 days";
                    cout << monthLength << endl;
                    break;
                case 0:
                    cout << "Goodbye!";
                    leave = true;
                    break;
                default:
                    cout << "Input Error, Month Invalid!! Only 12 months exist!" << endl;
                    break;
            }
        }
        else if (year <= GREGORIAN_CAL_START_YEAR)
        {
            cout << "\nGregorian Calendar was introduced in 1582. \n"
                    "The time periods vary as to when countries migrated from the Julian to Gregorian calendar. \n"
                    "Spain, Italy, and France for example switched over in 1582. \n"
                    "Great Britain didn't switch over to the Gregorian until 1752. \n"
                    "Other countries didn't switch over until more recent times - \n"
                    "Greece for example was using the Julian all the way up until 1922.\n\n";
            cout << "Please only enter years within acceptable range...\n";
            leave = true;
        }
        else if(year > ESTIMATED_HUMAN_EXTINCTION)
        {
            cout << "Humanity has a 95% probability of being extinct in 7,800,000 years,\n"
                    "according to J. Richard Gott's formulation of the controversial Doomsday argument,\n"
                    "which argues that we have probably already lived through half the duration of human history.";
            cout << "Please only enter years within acceptable range...\n";
            leave = true;
        }
        else
        {
            cout << "Input Error!!!";
            leave = true;
            break;
        }

    }while(leave != true);
   
    return 0;
}

/**Checks if a number is divisible by another number
 * returns true if yes, and false if no
 * @param num1 number that is being evaluated
 * @param num2 number it should/should'nt be divisible by
 * @return boolean that informs of result
 */
bool isDivisible (int num1, int num2)
{
    if (num1 % num2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
