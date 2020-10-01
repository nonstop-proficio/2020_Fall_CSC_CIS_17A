#include <iostream>
using namespace std;

//Prototype 
int **getData(int &,int &);                     //Get the Matrix Data

void prntDat(int **,int,int);     //Print the Matrix

int **augment(int **,int,int);     //Augment the original array

void destroy(int **,int);                       //Destroy the Matrix, i.e., reallocate memory

int main(){
	//your code here
	//------------------------ to call getData------------------------------
	int rowCount = 0, 
        colCount = 0;

    int ** arrPtr;

    arrPtr = getData(rowCount, colCount);
    
    //------------------------prntDat arrPtr------------------------------

    prntDat(arrPtr, rowCount, colCount);
    cout << endl;
    //------------------------ to call augment------------------------------
    
    int ** augPtr;
    
    augPtr = augment(arrPtr, rowCount, colCount);
    
    //------------------------prntDat augPtr------------------------------
    
    prntDat(augPtr, rowCount+1, colCount+1);
    
    //------------------------deallocate memory------------------------------
    
    destroy(arrPtr, rowCount);
    
    destroy(augPtr, rowCount);
    
	return 0;
}

//Definitions
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
        if(i != rowCount-1){
            cout << endl;
        }
        
    }
}

//-----------------------------augment-----------------------------
int **augment(int ** arrPtr, int rowCount, int colCount){
    
    int augRowCount = rowCount+1, 
        augColCount = colCount+1;
    
    int ** pointer;
    
    pointer = new int*[augRowCount];
    
    for(int i = 0; i < augRowCount; i++){
        pointer[i] = new int[augColCount];
    }

    for(int i = 0; i < augRowCount; i++){
        for(int j = 0; j < augColCount; j++){
            *(*(pointer+i)+j) = 0;
        }
    }
    
    for(int i = 0; i < rowCount; i++){
        for(int j = 0; j < colCount; j++){
            *(*(pointer+i+1)+j+1) = arrPtr[i][j];
        }
    }
    
    return pointer;
}

//-----------------------------destroy-----------------------------
void destroy(int ** arrPtr, int rowCount){
    for(int i =0; i < rowCount; i++){
        delete[] arrPtr[i];
    }
} 

