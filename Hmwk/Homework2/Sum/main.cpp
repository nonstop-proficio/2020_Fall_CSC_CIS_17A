#include <iostream>
using namespace std;

//Given prototypes
int *getData(int &);                //Return the array size and the array from the inputs

int *sumAry(const int *,int);       //Return the array with successive sums

void prntAry(const int *,int);      //Print the array


int main(){
	//your code here
    //------------------------ to call getData------------------------------
    //create int pointer
	int * arrPtr = nullptr;
	//variable arrSize
	int arrSize = 0;
	//dinamycally allocate and fill array, assigning returned pointer to arrPtr.
	arrPtr = getData(arrSize);

    //------------------------ to call sumAry------------------------------
    int * sumPtr = nullptr;

    sumPtr = sumAry(arrPtr, arrSize);

    //------------------------ print both arrays------------------------------
    prntAry(arrPtr, arrSize);
    cout << endl;
    prntAry(sumPtr, arrSize);

    delete [] arrPtr, sumPtr;

	return 0;
}


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

int *sumAry(const int * arrPtr, int arrSize){
    int * pointer;

    pointer = new int[arrSize+1];

    int sum;

    for(int i = 0; i < arrSize; i++){
        sum += arrPtr[i];
        if(i == 0){
            pointer[i] = arrPtr[i];    
        }
        else{
            pointer[i] = arrPtr[i]+sum-arrPtr[i];
        }
    }

    return pointer;
}

void prntAry(const int *arrPtr, int arrSize){
    for(int i = 0; i < arrSize; i++){
        if(i == arrSize-1){
            cout << *(arrPtr + i);
        }
        else{
            cout << *(arrPtr + i) << " ";
        }
    }
}

