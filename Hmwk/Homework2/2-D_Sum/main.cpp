#include <iostream>
using namespace std;

//Prototypes
int ** getData(int & ,int & );                 //Return the 2-D array and its size.

void prntDat(int ** arrPtr, int, int);   //Print the 2-D Array

void destroy(int **, int, int);               //Deallocate memory

int sum(int ** , int, int);      //Return the Sum

int main(){
	//your code here
    //------------------------ to call getData------------------------------
    int rowCount = 0, 
        colCount = 0;

    int ** arrPtr;

    arrPtr = getData(rowCount, colCount);

    //------------------------ to call prntDat------------------------------

    prntDat(arrPtr, rowCount, colCount);

    //------------------------ to call sum------------------------------

    int arrSum;

    arrSum = sum(arrPtr, rowCount, colCount);

    cout << arrSum;
    
    
    //------------------------ destroy------------------------------
    
    destroy(arrPtr, rowCount, colCount);
    
	return 0;
}


//Function Definitions 
//-----------------------------getData-----------------------------
int ** getData(int & rowCount, int & colCount){
    cin >> rowCount >> colCount;

    int ** pointer;
    
    pointer = new int*[rowCount];
    
    for(int i = 0; i < rowCount; i++){
        pointer[i] = new int[colCount];
    }

    for(int i = 0; i < rowCount; i++){
        for(int j = 0; j < colCount; j++){
            cin >> *(*(pointer+i)+j);
        }
    }

    return pointer;
}


//-----------------------------prntDat-----------------------------
void prntDat(int** arrPtr, int rowCount, int colCount){
    for(int i = 0; i < rowCount; i++){
        for(int j = 0; j < colCount; j++){
            if(j == colCount-1){
                cout << *(*(arrPtr+i)+j);
            }
            else{
                cout << *(*(arrPtr+i)+j) << " ";
            }
            
        }
        cout << endl;
    }
}


//-----------------------------sum-----------------------------
int sum(int ** arrPtr, int rowCount, int colCount){
    
    int sum = 0;
    
    for(int i = 0; i < rowCount; i++){
        for(int j = 0; j < colCount; j++){
            sum += *(*(arrPtr+i)+j);
        }
    }
    
    return sum;
} 


void destroy(int ** arrPtr, int rowCount, int colCount){
    for(int i =0; i < rowCount; i++){
        delete[] arrPtr[i];
    }
} 




