
/* 
 * File:   main.cpp
 * Author: Antero
 *
 * Created on October 20, 2020
 */

//System Libraries 
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Function Prototypes
void    getStr(string &);        //Get string from user 
string encrypt(string );        //Returns encrypted string
string decrypt(string );        //Decrypts encrypted string

//-------------------------------MAIN starts here-------------------------------
int main(int argc, char** argv) {
    cout << "Press Enter to Begin" << endl;
    string data = " ";

    cin.ignore();
    getStr(data);

    cout << "data:  " << data << endl;

    string ncryptd = data;
    ncryptd = encrypt(data);

    cout << "encrypted data:   " << ncryptd << endl;

    return 0;
}
//------------------------------MAIN ends here----------------------------------

//Function Definitions


//Gets input from user
void getStr(string &data){
    cout << "Enter the 4 digit integer you would like to encrypt: " << endl;

    string input = " ";
    
    getline(cin, input);

    data = input;
}

//Encrypts integer provided by user
string encrypt(string data){

    string ncryptd = data;

    int sz = data.size();

    char * pointer = nullptr;

    pointer = new char[sz];

    for(int i = 0; i < sz; i++){
        pointer[i] = data[i];
    }

    //ENCRYPT-------------------------------------------------------------------
    //need to process the array contents here, then save to string and return
    char temp1 = '0',
         temp2 = '0',
         temp3 = '0',
         temp4 = '0';
    //swap 1st with 3rd
    temp1 = pointer[0];
    temp2 = pointer[1];
    temp3 = pointer[2];
    temp4 = pointer[3];

    pointer[0] = temp3;
    pointer[1] = temp4;
    pointer[2] = temp1;
    pointer[3] = temp2;

    //---------------------------------------------------------------------------
    //write contents of array to string
    for(int i = 0; i < sz; i++){
        ncryptd[i] = pointer[i];
    }


    delete pointer;
    //return encrypted string
    return ncryptd;
}