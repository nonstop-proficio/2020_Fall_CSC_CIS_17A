//Program the convert US Dollars to Japanese Yen and European Euros,
//Storing exchange rate in constants : YEN_PER_DOLLAR and EUROS_PER_DOLLAR
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//prototypes
void displayMenu();
int getMenuChoice();

int main(int argc, char** argv) {
    //Variables
    const double YEN_PER_DOLLAR = 106.60,
                 EUROS_PER_DOLLAR = 0.85;
    
    double dollarAmount = 0;
    int convertChoice;
    
    bool leave = false; // provides exit option in currency selection menu
    
    do
    {
        if (dollarAmount == 0) //if dollar amount needs to be entered
        {
            //Get dollar amount to be converted from user
            cout << "Please enter the amount ($USD) you would like to convert: ";
            cin >> dollarAmount;

            if (dollarAmount > 0) //check dollar amount for adequate value 
            {
                //ask for what currency it should be converted to
                displayMenu();
                convertChoice = getMenuChoice();

                switch (convertChoice)
                {

                    double convertedCurrency;  

                        case 1:
                            convertedCurrency = dollarAmount * YEN_PER_DOLLAR;
                            cout << "Your converted amount is: " << fixed << setprecision(2) 
                                    << showpoint << char(165) << convertedCurrency << endl;
                            dollarAmount = 0;
                            break;
                        case 2:   
                            convertedCurrency = dollarAmount * EUROS_PER_DOLLAR;
                            cout << "Your converted amount is: " << fixed << setprecision(2) 
                                    << showpoint << char(163) << convertedCurrency << endl;
                            dollarAmount = 0;
                            break;
                        case 0:
                            cout << "Goodbye!";
                            leave = true;
                            break;
                        default:
                            cout << "Input Error! Please select a currency! (1 = JPY, 2 = EUR) then press ENTER!" << endl;
                            break;
                }
            }
            else //if dollar amount is below 0, reset value
            {
                cout << "Enter a dollar amount greater than 0!\n" << endl;
                dollarAmount = 0;
            }
        }
        else //if dollar amount has been entered, but currency selection was wrong
        {
            //ask for what currency it should be converted to
            displayMenu();
            convertChoice = getMenuChoice();
            
            switch (convertChoice)
            {

                double convertedCurrency;  

                    case 1: // convert to yen
                        convertedCurrency = dollarAmount * YEN_PER_DOLLAR;
                        cout << "Your converted amount is: " << fixed << setprecision(2) 
                                << showpoint << char(165) << convertedCurrency << endl;
                        dollarAmount = 0;
                        break;
                    case 2: //convert to euro
                        convertedCurrency = dollarAmount * EUROS_PER_DOLLAR;
                        cout << "Your converted amount is: " << fixed << setprecision(2) 
                                << showpoint << char(163) << convertedCurrency << endl;
                        dollarAmount = 0;
                        break;
                    case 0: // exit program
                        cout << "Goodbye!";
                        leave = true;
                        break;
                    default: //error message
                        cout << "Input Error! Please select a currency! (1 = JPY, 2 = EUR) then press ENTER!" << endl;
                        break;
            }
        }
    
    }while(leave != true);
return 0;
}

//function definitions

//displays a short menu for currency slelection
void displayMenu()
{
    //Ask user what currency they want USD converted to
            cout << "What currency would you like to convert to?: " << endl;
            cout << "1. Japanese Yen (JPY).\n";
            cout << "2. Euro (EUR).\n\n";
            cout << "0. EXIT PROGRAM\n\n";
}

/**Gets selection from user
 * 
 * @return returns the menu selection which is an int
 */
int getMenuChoice()
{
    int menuChoice;
    cin >> menuChoice;
    return menuChoice;
}