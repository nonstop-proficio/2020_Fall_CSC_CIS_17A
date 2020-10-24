/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: anter
 *
 * Created on October 20, 2020
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int nInt = 1;
    unsigned int nUInt = 1;

    double d = 1;
    //unsigned double ud;

    char cI = 1;
    unsigned char ucI = 1;

    float fI = 1; 
    //unsigned float;

    short sI = 1;
    unsigned short usI = 1;

    int factorial;
    cin >> factorial;

    for(int i = 0; i < factorial; i++){
        cout << nInt << endl;
        nInt *= (nInt++);
    }   

    return 0;
}

