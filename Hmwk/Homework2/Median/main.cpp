#include <iostream>
#include <iomanip>
using namespace std;

int * getData(int &);        //Return the array and size of the array

void prntDat(int *,int);    //Print the integer array

float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data

void prntMed(float *);     //Print the median Array

//Global arrSize for easy access from functions
int arrSize = 0;

int main(){
    
    //------------------------ to call getData------------------------------
    //create int pointer
	int * arrPtr = nullptr;
	//variable arrSize
	
	//dinamycally allocate and fill array, assigning returned pointer to arrPtr.
	arrPtr = getData(arrSize);
	
	//------------------------to call prntDat------------------------------
	prntDat(arrPtr, arrSize);
	
	//------------------------to call median------------------------------
	//create float pointer
	float * medPtr = nullptr;
	//variable medArrSz
	int medArrSz = arrSize+2;
	//dynamically allocate and fill median array, assigning returned pointer to medPtr
	medPtr = median(arrPtr, medArrSz);
	
	
	//------------------------to call prntMed------------------------------
	prntMed(medPtr);
	
	//------------------------deallocate memory------------------------------
	delete [] arrPtr, medPtr;
	
	return 0;
}

//function definitions
int * getData(int &arrSize)
{
    cin >> arrSize;
    
    int * pointer;
    
    pointer = new int[arrSize];
    
    for(int i = 0; i < arrSize; i++){
        cin >> pointer[i];
    }
    
    return pointer;
}


void prntDat(int * arrPtr, int arrSize){
    for(int i = 0; i < arrSize; i++){
        if(i == arrSize-1){
            cout << *(arrPtr + i) << endl;
        }
        else{
            cout << *(arrPtr + i) << " ";
        }
    }
}

float *median(int * arrPtr, int medArrSz){
    
    float * pointer;
    
    pointer = new float[medArrSz];
    
    pointer[0] = medArrSz;
    
    float sum = 0;
    float median;
    
    for(int i = 0; i < arrSize; i++)
    {
        sum += arrPtr[i];
    }
    
    if(arrSize % 2 == 0){
        //If even, get next number in arrPtr and divide by 2
        median  = arrPtr[arrSize / 2];
        median = (median + arrPtr[arrSize / 2 - 1]) / 2;
    }
    if(arrSize % 2 != 0){
        median = sum / arrSize;
    }
    
   
    
    //This calculates the median for odd length arrPtr arrays
    //double median  = arrPtr[arrSize / 2];
    //Check if arrPtr array has even length
    /*
    if(arrSize % 2 == 0){
        //If even, get next number in arrPtr and divide by 2
        median = (median + arrPtr[arrSize / 2 - 1]) / 2;
    }
    */
    //Assign claculated median to corresponding element of medArr
    pointer[1] = median;
    
    //Copy the rest of arrPtr array to medPtr arr
    for(int i = 2; i < medArrSz; i++){
        pointer[i] = arrPtr[i-2];
    }
    return pointer;
}


void prntMed(float * medPtr){
    
    int len = arrSize+2;
    
    for(int i = 0; i < len; i++){
        if(i > 0) {
            cout << fixed << setprecision(2);
        }
        if(i == len-1){
            cout << *(medPtr + i);
        }
        else{
            cout << *(medPtr + i) << " ";    
        }
        
    }
}