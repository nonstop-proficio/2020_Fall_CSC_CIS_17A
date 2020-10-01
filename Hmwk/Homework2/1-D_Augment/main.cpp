#include <iostream>
using namespace std;


//Prototypes 
int *getData(int &);//Read the array

int *augment(const int *,int);//Augment and copy the original array

void prntAry(const int *,int);//Print the array

int arrSize = 0;

int main(){
	//your code here
	
	//------------------------ to call getData------------------------------
    //create int pointer
	int * arrPtr = nullptr;
	//variable arrSize
	
	//dinamycally allocate and fill array, assigning returned pointer to arrPtr.
	arrPtr = getData(arrSize);

    //------------------------ to call augment------------------------------
    
    int * augPtr = nullptr;
    
    int augSize = arrSize+1;
    
    augPtr = augment(arrPtr, arrSize);
    
    //------------------------ print both arrays ------------------------------
    prntAry(arrPtr, arrSize);
    cout << endl;
    prntAry(augPtr, augSize);
    
    //------------------------ deallocate memory ------------------------------
    
    delete [] augPtr, arrPtr;
    
	return 0;
}

//Definitions 

int *getData(int &)
{
    cin >> arrSize;
    
    int * pointer;
    
    pointer = new int[arrSize];
    
    for(int i = 0; i < arrSize; i++){
        cin >> pointer[i];
    }
    
    return pointer;
}


int *augment(const int * arrPtr, int arrSize){
    
    int * pointer;

    pointer = new int[arrSize+1];

    int aug = (arrPtr[0]-1);

    for(int i = 0; i < arrSize+1; i++){
        
        if(i == 0){
            pointer[i] = aug;    
        }
        else{
            pointer[i] = arrPtr[i-1];
        }
    }
    
    return pointer;
}


void prntAry(const int * arrPtr, int arrSize){
    
    for(int i = 0; i < arrSize; i++){
        if(i == arrSize-1){
            cout << *(arrPtr + i);
        }
        else{
            cout << *(arrPtr + i) << " ";
        }
    }
}