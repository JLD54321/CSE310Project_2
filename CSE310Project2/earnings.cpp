#include "defns.h"
#include "utility.h"
#include <iostream>
#define MAX_YEARS 60

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
    struct SOC socArray[NUM_OCC];

    //cout << "done" << endl;
    //calling queries handler
    string queriesNum;
    getline(cin, queriesNum);
    for(int i = 0; i < stoi(queriesNum); i++) {
        queryPrompt(earningsArray, socArray, year);
    }
    return 0;
}//end of main
