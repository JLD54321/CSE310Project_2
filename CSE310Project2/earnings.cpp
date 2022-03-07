#include "defns.h"
#include <string.h>
#include "utility.h"
#include <iostream>
#include <istream>
#include <sstream>
#include "earnings.h"
#include "max-heap.h"
#define MAX_YEARS 50

using namespace std;
// Created by cse310 on 2/23/22.
int main(int argc, char* argv[]){
    //check for incorrect number of arguments
    if ((argc > 4) || (argc < 2)) {
            cout << "Error incorrect number of arguments" << endl;
            return -1;
    }

    //check for valid year within range
    string year = &argv[1][0];
    if((stoi(year) < 1960 )||(stoi(year) > 2020)){
        cout << "Error not a valid year" << endl;
        return -1;
    }
    //Read in files and calling respective function to store in to structs
    struct earnings earningsArray[MAX_YEARS];
    ReadInEarnings(earningsArray);

    struct SOC socArray[NUM_OCC];
    ReadInOccupation(stoi(year),socArray);

    string queriesNum;
    getline(cin, queriesNum);
    for(int i = 0; i < stoi(queriesNum); i++) {
        queryPrompt(earningsArray);
    }

    //call Max_heapify for each respective function
   // BUILD_MAX_HEAP_SOC(socArray,OCC_LEN);

  //  cout << endl;

   // for(int i = 0; i < NUM_OCC; i++){
   //     cout << socArray[i].total << ", ";
    //}

    return 0;
}//end of main
