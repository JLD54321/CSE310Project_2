#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "utility.h"
#include <string.h>
#include "defns.h"
#include "max-heap.h"
#define MAX_YEARS 60

using namespace std;

//Function to store values into their respective field
//after they have been constructed into a string for SOC struct
void StoreInSOCStruct(struct SOC soc[], int fieldNum, char fieldVal[], int socIndex){
    switch (fieldNum) {
        case 0:
            //field occupation
            strcpy(soc[socIndex].occupation,fieldVal);
            break;
        case 1:
            //field SOC Code
            strcpy(soc[socIndex].SOC_code,fieldVal);
            break;
        case 2:
            //field total
            soc[socIndex].total = atoi(fieldVal);
            break;
        case 3:
            //field female
            soc[socIndex].female = atoi(fieldVal);
           break;
        case 4:
            //field male
            soc[socIndex].male = atoi(fieldVal);
           break;
    }
    return;
}

//Function to store values into their respective field
//after they have been constructed into a string for Earning struct
void StoreInEarningsStruct(struct earnings Data[],int field, string str, int index){
    switch (field) {
        case 0:
            if(str == "N"){
                Data[index].year = 0;
            }else {
                Data[index].year = stoi(str);
            }
            break;
        case 1:
            if(str == "N"){
                Data[index].male_total = 0;
            }else {
                Data[index].male_total = stoi(str);
            }
            break;
        case 2:
            if(str == "N"){
                Data[index].male_with_earnings = 0;
            }else {
                Data[index].male_with_earnings = stoi(str);
            }
            break;
        case 3:
            if(str == "N"){
                Data[index].male_earnings = 0;
            }else {
                Data[index].male_earnings = stoi(str);
            }
            break;
        case 4:
            if(str == "N"){
                Data[index].male_earnings_moe = 0;
            }else {
                Data[index].male_earnings_moe = stoi(str);
            }
            break;
        case 5:
            if(str == "N"){
                Data[index].female_total = 0;
            }else {
                Data[index].female_total = stoi(str);
            }
            break;
        case 6:
            if(str == "N"){
                Data[index].female_with_earnings = 0;
            }else{
                Data[index].female_with_earnings = stoi(str);
            }
            break;
        case 7:
            if(str == "N"){
                Data[index].female_earnings = 0;
            }else {
                Data[index].female_earnings = stoi(str);
            }
            break;
        case 8:
            if(str == "N"){
               Data[index].female_earnings_moe = 0;
            }else {
                Data[index].female_earnings_moe = stoi(str);
            }
            break;
    }
    return;
}

//Function to read in data from Earnings-1960-2019.csv file
void ReadInEarnings (earnings Data[]) {
    //open file Earnings data file
    ifstream infile;
    infile.open("Earnings-1960-2019.csv");
    string line;

    //Skip first 8 lines
    for (int i = 0; i < 1; i++) {
        getline(infile, line);
    }

    //Read in values into their respective field for the Earnings Data struct
    Data[MAX_YEARS];
    for(int i = 0; i < MAX_YEARS; i++){
        Data->year = 0;
        Data->male_total = 0;
        Data->male_with_earnings = 0;
        Data->male_earnings = 0;
        Data->male_earnings_moe = 0;
        Data->female_total = 0;
        Data->female_with_earnings = 0;
        Data->female_earnings = 0;
        Data->female_earnings_moe = 0;
    }

    //initialize values used in string building
    char c;
    bool inQuote = false;
    string str = "";
    int field = 0;
    int index = 0;

    while (!infile.eof()) {
        //get next character
        infile.get(c);
        //check if character = double quote inQuote and if inQuote set inQuote to false
        //else if not inQuote set it to true
        if (c == '"') {
            if (inQuote) {
                inQuote = false;
            } else {
                inQuote = true;
            }
            //check if comma and inQuote and if not inQuote call StoreInEarningsStruct
        } else if (c == ',') {
            if (!inQuote) {
                if (!str.empty()) {
                    StoreInEarningsStruct(Data, field, str, index);
                }
                str = "";
                field++;
            }
            //check for end of file, "N" and newline and call StoreInEarningsStruct
        } else if ((c == '\n') || (cin.eof())) {
           if(!str.empty()) {
                StoreInEarningsStruct(Data, field, str, index);
           }
            //reseting values after newline and indexing array index for Data array
            str = "";
            field = 0;
            index++;
        }else if(str == "N"){
            StoreInEarningsStruct(Data, field, str, index);
            str = "";
            field++;
        }else {
            //constructing string if not comma, double quote or newline
            str = str + c;
        }
    }
    infile.close();
    return;
}

//Function to read in values from Occupation files
void ReadInOccupation (int year, struct SOC soc[]){
    //open file with respective year of Occupations file
    ifstream infile;
    string fileOcc = "Occupation-Dist-All-" + to_string(year) + ".csv";
    infile.open(fileOcc);
    string line;

    //Skip first 5 lines
    for (int i = 0; i < 1; i++) {
        getline(infile, line);
    }

    // Initialize temporary SOC structure called node
    // to be used to fill in soc array when calling
    // ReadInOccupation

    //Read in values into their respective field for the SOC Data struct
    char c;
    bool inQuote = false;
    char charArray[OCC_LEN];
    int field = 0, index = 0, i = 0;
    do {
        infile.get(c);
        if (c == '"') {
            //check for double quote and set inQuote to true if in Quote
            // and to false if not inQuote
            if (inQuote) {
                inQuote = false;
            } else {
                inQuote = true;
            }
        } else if (c == ',') {
            //check for inQuote and if inQuote skip value
            //otherwise call StoreInSOCStruct
            if (!inQuote) {
                charArray[i] = '\0';
                StoreInSOCStruct(soc, field, charArray, index);
                //charArrayReset(charArray);
                field++;
                i = 0;
            }
        } else if ((c == '\n') || (infile.eof())) {
                charArray[i] = '\0';
                StoreInSOCStruct(soc, field, charArray, index);
                //reseting values after newline and indexing array index
                //to move on to next value in soc array
                field = 0;
                i = 0;
                index++;
        } else {
            //add to char array
            charArray[i] = c;
            i++;
        }
    } while(!infile.eof());
    //close file
    infile.close();
    return;
}

void queryPrompt(earnings earningsArray[], SOC socArray[], string year){
    //reading in 4 values from cin
    string query;
    getline(cin,query);
    if(query == ""){
        cout << "Query failed." << endl;
        return;
    }

    //reading in query to strArray to parse fields
    string strArray[4];
    int i = 0;
    stringstream iss(query);
    while(i < 4){
        iss >> strArray[i];
        i++;
    }

    //Echoing Query
    cout << "Query:";
    for(int i = 0; i < 4; i++){
        cout << " " << strArray[i];
    }
    cout << endl;
    cout << endl;

    //checking each field to see if it is valid
    //and calling respective function based on query

        //checking to see if first field is valid
    if(strArray[0]  != "find"){
        cout << "Error field 1" << endl;
        //checking to see if field 2 is valid
    }else if((strArray[1] != "ratio") && (strArray[1] != "max")){
        cout << "Query failed." << endl;
        //checking if second field is ratio
    }else if(strArray[1] == "ratio"){
        //checking if 3rd field is within range
        if((stoi(strArray[2]) < 1960) || (stoi(strArray[2]) > 2019)){
            cout << "Query failed." << endl;
        //checking if 4th field is within range
        }else if((stoi(strArray[3]) < 1960) || (stoi(strArray[3]) > 2019)){
            cout << "Query failed."<< endl;
        }else{
            //call find Ratio function
            ReadInEarnings(earningsArray);
            findRatio(earningsArray, stoi(strArray[2]), stoi(strArray[3]));
        }
        //checking if 2nd field is max
    }else if(strArray[1] == "max"){
        //check if 3rd field is either total, male or female
        if((strArray[2] != "total") && (strArray[2] != "female") && (strArray[2] != "male")){
            cout << "Query failed." << endl;
        } else{
            //check if 4th field is in range
            if((stoi(strArray[3]) > 50) || (0 > stoi(strArray[3]))){
                cout << "Query failed." << endl;
            }else{
                //call findMax function
                ReadInOccupation(stoi(year),socArray);
                findMax(socArray, strArray[2], stoi(year), stoi(strArray[3]));
            }
        }
    }
    return;
}

//function for finding ratio between female and male earnings
void findRatio(earnings array[], int year1, int year2){
    //initializing and saving values being used for
    //printing and later calculations
    int yearSave1 = year1;
    int yearSave2 = year2;
    int startIndex = 2019 - yearSave1;
    int endIndex = 2019 - yearSave2;

    //printing description of query
    cout << "The female-to-male earnings ratio for ";
    cout << to_string(yearSave1) << "-" ;
    cout << to_string(yearSave2) << ":" << endl;

    //calculation and printing of female-to-male ratio
    //for their respective years with 1 decimal place
    //not rounding
    for(int i = startIndex ;i >= endIndex ;i--){
        float percent = ((float)array[i].female_earnings / (float)array[i].male_earnings) * 100;
        percent = percent - .05;
        cout << "\t" << array[i].year << ": " << fixed << setprecision(1) << percent << "%" << endl;
    }
    cout << endl;
    return;
}

//function for finding max number of workers out of all
//occupations in file
void findMax(SOC array[], string workerType, int year, int numberOfTimes){
    int size = 505;
    if(workerType == "total") {
        BUILD_MAX_HEAP_SOCTotal(array, size);
    }else if(workerType == "female"){
        BUILD_MAX_HEAP_SOCFemale(array,size);
    }else{
        BUILD_MAX_HEAP_SOCMale(array,size);
    }
    cout << "Top " << numberOfTimes << " occupations in " << year << " for " << workerType << " workers:" << endl;
    for(int i = 0; i < numberOfTimes; i++) {
        cout << "\t" << array[0].occupation << ": ";
        if (workerType == "male") {
            setlocale(LC_NUMERIC,"");
            printf("%'d\n",array[0].male);
            array[0].male = 0;
            BUILD_MAX_HEAP_SOCMale(array,size);
        } else if (workerType == "female") {
            setlocale(LC_NUMERIC,"");
            printf("%'d\n",array[0].female);
            array[0].female = 0;
            BUILD_MAX_HEAP_SOCFemale(array,size);
        } else if (workerType == "total"){
            setlocale(LC_NUMERIC,"");
            printf("%'d\n",array[0].total);
            array[0].total = 0;
            BUILD_MAX_HEAP_SOCTotal(array, size);
        }
    }
    return;
}