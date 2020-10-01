#include <iostream>
using namespace std;

int *getData(int &);            //Fill the array

int *sort(const int *,int);      //Sort smallest to largest

int *reverse(const int *,int);  //Sort in reverse order

void prntDat(const int *,int);  //Print the array

int main(){
	
	//------------------------ to call getData------------------------------
    //create int pointer
	int * arrPtr = nullptr;
	//variable arrSize
	int arrSize = 0;
	//dinamycally allocate and fill array, assigning returned pointer to arrPtr.
	arrPtr = getData(arrSize);
	
	//------------------------ to call sort------------------------------
	int * srtdPtr = nullptr;

    srtdPtr = sort(arrPtr, arrSize);

    //------------------------ prntDat of sorted array------------------------------
    prntDat(srtdPtr, arrSize);
    cout << endl;
    //------------------------to call reverse------------------------------
	int * revrArr = nullptr;
	
	revrArr = reverse(srtdPtr, arrSize);

    //------------------------ prntDat of reversed array------------------------------
    prntDat(revrArr, arrSize);
    
    delete [] arrPtr, srtdPtr, revrArr;

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


int *sort(const int * arrPtr, int arrSize){
    
    int * pointer;

    pointer  = new int[arrSize];

    for(int i = 0; i < arrSize; i++){
        pointer[i] = arrPtr[i];
    }

    int startScan, minIndex, minValue;
    for (startScan = 0; startScan < (arrSize - 1); startScan++)
    {
       minIndex = startScan;
       minValue = pointer[startScan];
       for(int index = startScan + 1; index < arrSize; index++)
       {
          if (pointer[index] < minValue)
          {
             minValue = pointer[index];
             minIndex = index;
          }
       }
       pointer[minIndex] = pointer[startScan];
       pointer[startScan] = minValue;
    }

    return pointer;

}

int *reverse(const int * srtdPtr, int arrSize){

    int * pointer;

    pointer =  new int[arrSize];

    for(int i = arrSize-1, j = 0; i > -1, j < arrSize; i--, j++){
        pointer[j] = srtdPtr[i];
    }

    return pointer;
}

void prntDat(const int * arrPtr, int arrSize){
    for(int i = 0; i < arrSize; i++){
        if(i == arrSize-1){
            cout << *(arrPtr + i);
        }
        else{
            cout << *(arrPtr + i) << " ";
        }
    }
}

