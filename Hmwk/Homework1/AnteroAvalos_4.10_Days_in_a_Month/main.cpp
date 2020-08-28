#include <iostream>
#include <iomanip>
using namespace std;

//function prototypes
bool isDivisible (int num1, int num2);

int main()
{
    //Variables
    int month, year;

    //Ask user for month and year
    cout << "Enter a month: ";
    cin >> month;

    if (month >= 1 && month <= 12)
    {
        cout << "Enter a year: ";
        cin >> year;

        switch (month)
        {
            case 1:
                cout << "31 days";
                break;
            case 2:
                if (isDivisible(year, 100) == true && (isDivisible(year, 400) == true))
                {
                    cout << "29 days";
                }
                else if (isDivisible(year, 100) == false && (isDivisible(year, 4) == true))
                {
                    cout << "29 days";
                }
                else
                {
                    cout << "28 days";
                }
                break;
            case 3:
                cout << "31 days";
                break;
            case 4:
                cout << "30 days";
                break;
            case 5:
                cout << "31 days";
                break;
            case 6:
                cout << "31 days";
                break;
            case 7:
                cout << "31 days";
                break;
            case 8:
                cout << "31 days";
                break;
            case 9:
                cout << "30 days";
                break;
            case 10:
                cout << "31 days";
                break;
            case 11:
                cout << "30 days";
                break;
            case 12:
                cout << "31 days";
                break;
            default:
                cout << ;
                break;
        }
    }
    else
    {
        cout << "Please enter a month between 1 and 12!" << endl;
    }
    
    return 0;
}

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
