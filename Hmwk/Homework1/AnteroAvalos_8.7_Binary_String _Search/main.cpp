#include <iostream>
#include <string>
using namespace std;
//Function Prototypes
int binarySearch(const string[], int, string); //Uses binary search to find the index of an element in array of strings
void sortArr(string[], int); //Sorts string array in alphabetical order using bubble sort algorithm
void dispArr(string[], int); //Display contents of str array
string getStr();             //Get input from user as string

int main()
{
    //Variables
	const int NUM_NAMES = 20; //Size of names array
    //Array of strings, contains names (not sorted)
	string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                               "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                               "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",
                               "Looney, Joe", "Wolfe, Bill", "James, Jean",
                               "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
                               "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
                               "Pike, Gordon", "Holland, Beth" };    
    string name; //String to hold the name for search

    //Array of strings needs to be sorted before the binary search takes place
    sortArr(names, NUM_NAMES);

    //Get string(name) for search from user
    name = getStr();
    
    //Apply binary search to the sorted array
    int location = binarySearch(names, NUM_NAMES, name);

    //Output result from binary search
    if(location == -1){
        cout << name << " was not found in array. Please enter a name that matches the records.\n" 
                "Also, make sure to use the proper format!" << endl;
    }
    else{
        cout << name << " is located at index " << location << " of the names array (which was sorted alphabetically).";
    }
	return 0;
}

//Function Definitions

/**
 * @brief Uses binary search to find the index of an element in array of strings
 * 
 * @param array array you want sorted
 * @param size size of the array that will be sorted
 */
void sortArr(string array[], int size){
   bool swap;
   string temp;

   do
   {
      swap = false;
      for (int count = 0; count < (size - 1); count++)
      {
         if (array[count] > array[count + 1])
         {
            temp = array[count];
            array[count] = array[count + 1];
            array[count + 1] = temp;
            swap = true;
         }
      }
   } while (swap);
}

/**
 * @brief Sorts string array in alphaetical order using bubble sort alg
 * 
 * @param array  name of string array to be sorted
 * @param numElems size of array
 * @param value string that the search is trying to locate
 * @return int location of string in array -  returns -1 if string not found
 */
int binarySearch(const string array[], int numElems, string value){
    int first = 0,              // First array element
        last = numElems - 1,        // Last array element
        middle,              // Midpoint of search 
        position = -1;       // Position of search value
    
    bool found = false;         // Flag
    
    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        // Calculate midpoint
        if (array[middle] == value)
        // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (array[middle] > value) // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1; // If value is in upper half
    }
        
    return position;
}

/**
 * @brief Display contents of str array
 * 
 * @param arr array to display contents of 
 * @param size size of array to be displayed
 */
void dispArr(string arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << endl ;
    }
}

/**
 * @brief Get a Str object from user
 * 
 * @return string 
 */
string getStr(){
    string name;
    cout << "Please enter the name you want to search for. Use the following format:" << endl;
    cout << "Last, First (e.x. 'Doe, John'):   ";
    getline(cin, name);
    return name;
}