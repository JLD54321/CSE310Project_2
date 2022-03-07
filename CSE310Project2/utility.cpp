#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "utility.h"
#include <string.h>
#include "defns.h"
#define MAX_YEARS 50

using namespace std;

//Function to store values into their respective field
//after they have been constructed into a string for SOC struct
void StoreInSOCStruct(struct SOC soc[], struct SOC *tempSoc, int fieldNum, string fieldVal, int socIndex){
    int sizeOcc, sizeSOC;
    switch (fieldNum) {
        case 0:
            sizeOcc = fieldVal.size();
            for(int i = 0; i < sizeOcc; i ++) {
                soc->occupation[i] = fieldVal.c_str()[i];
            }
            for(int i = 0; i < sizeOcc; i ++) {
               // cout << soc->occupation[i];
            }
           // cout << " ";
            break;
        case 1:
            sizeSOC = fieldVal.size();
            for(int i = 0; i < sizeSOC; i++) {
                soc[socIndex].occupation[i] = fieldVal.c_str()[i];
              //  cout << soc[socIndex].occupation[i];
            }
           // cout << " ";
            break;
        case 2:
            soc[socIndex].total = stoi(fieldVal);
           // cout << soc[socIndex].total << " ";
            break;
        case 3:
            soc[socIndex].female = stoi(fieldVal);
           // cout << soc[socIndex].female << " ";
            break;
        case 4:
            soc[socIndex].male = stoi(fieldVal);
           // cout << soc[socIndex].male << " ";
            break;
    }
    return;
}

//Function to store values into their respective field
//after they have been constructed into a string for Earning struct
void StoreInEarningsStruct(struct earnings Data[],struct earnings *node,int field, string str, int index){
    switch (field) {
        case 0:
            if(str == "N"){
                node->year = -1;
               // cout << "Year: " << node->year << endl;
            }else {
                node->year = stoi(str);
               // cout << "Year: " << node->year << endl;
            }
            break;
        case 1:
            if(str == "N"){
                node->male_total = -1;
            //    cout << "Male total: " << node->male_total << endl;
            }else {
                node->male_total = stoi(str);
            //    cout << "Male total: " << node->male_total << endl;
            }
            break;
        case 2:
            if(str == "N"){
                node->male_with_earnings = -1;
            //    cout << "Male with earnings: " << node->male_with_earnings << endl;
            }else {
                node->male_with_earnings = stoi(str);
            //    cout << "Male with earnings: " << node->male_with_earnings << endl;
            }
            break;
        case 3:
            if(str == "N"){
                node->male_earnings = -1;
            //    cout << "Male earnings: " << node->male_earnings << endl;
            }else {
                node->male_earnings = stoi(str);
            //    cout << "Male earnings: " << node->male_earnings << endl;
            }
            break;
        case 4:
            if(str == "N"){
                node->male_earnings_moe = -1;
             //   cout << "Male earnings moe: " << node->male_earnings_moe << endl;
            }else {
                node->male_earnings_moe = stoi(str);
              //  cout << "Male earnings moe: " << node->male_earnings_moe << endl;
            }
            break;
        case 5:
            if(str == "N"){
                node->female_total = -1;
             //   cout << "Female total: " << node->female_total << endl;
            }else {
                node->female_total = stoi(str);
               // cout << "Female total: " << node->female_total << endl;
            }
            break;
        case 6:
            if(str == "N"){
                node->female_with_earnings = -1;
              //  cout << "Female with earnings: " << node->female_with_earnings << endl;
            }else{
                node->female_with_earnings = stoi(str);
               // cout << "Female with earnings: " << node->female_with_earnings << endl;
            }
            break;
        case 7:
            if(str == "N"){
                node->female_earnings = -1;
               // cout << "Female earnings: " << node->female_earnings<< endl;
            }else {
                node->female_earnings = stoi(str);
               // cout << "Female earnings: " << node->female_earnings << endl;
            }
            break;
        case 8:
            if(str == "N"){
                node->female_earnings_moe = -1;
                //cout << "Female earnings moe: " << node->female_earnings_moe << endl;
            }else {
                //cout << str;
                node->female_earnings_moe = stoi(str);
                //cout << "Female earnings moe: " << node->female_earnings_moe << endl;

            }
            int index = 2019-node->year;
            Data[index].year = node->year;
            Data[index].male_total = node->male_total;
            Data[index].male_with_earnings = node->male_with_earnings;
            Data[index].male_earnings = node->male_earnings;
            Data[index].male_earnings_moe = node->male_earnings_moe;
            Data[index].female_total = node->female_total;
            Data[index].female_with_earnings = node->female_with_earnings;
            Data[index].female_earnings = node->female_earnings;
            Data[index].female_earnings_moe = node->female_earnings_moe;
          //  cout << Data[index].year << " " << Data[index].male_total << " " << Data[index].male_with_earnings << " " << Data[index].male_earnings << " " << Data[index].male_earnings_moe << " ";
           // cout << Data[index].female_total << " " << Data[index].female_with_earnings << " " << Data[index].female_earnings << " " << Data[index].female_earnings_moe << endl;
            break;
    }
}

//Function to read in data from Earnings-1960-2019.csv file
void ReadInEarnings (earnings Data[]) {
    //open file Earnings data file
    ifstream infile;
    infile.open("Earnings-1960-2019.csv");
    string line;

    //Skip first 8 lines
    for (int i = 0; i < 2; i++) {
        getline(infile, line);
    }

    //Read in values into their respective field for the Earnings Data struct
    struct earnings node;
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
    string str;
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
                if (str.empty()) {
                } else {
                    StoreInEarningsStruct(Data, &node, field, str, index);
                }
                str = "";
                field++;
            }
            //check for end of file, "N" and newline and call StoreInEarningsStruct
        } else if ((str== "N") || (c == '\n') || (cin.eof())) {
            if(str.empty()){
            }else {
                StoreInEarningsStruct(Data,&node, field, str, index);
            }
            //reseting values after newline and indexing array index for Data array
            str = "";
            field = 0;
            index++;
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
    for (int i = 0; i < 2; i++) {
        getline(infile, line);
    }

    // Initialize temporary SOC structure called node
    // to be used to fill in soc array when calling
    // ReadInOccupation
    struct SOC node;

    //Read in values into their respective field for the SOC Data struct
    char c;
    bool inQuote = false;
    string str;
    int field = 0, index = 0;
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
                if(!str.empty()){
                    StoreInSOCStruct(soc, &node, field, str, index);
                }
                str = "";
                field++;
               // cout << endl;
            }
        } else if ((c == '\n') || (infile.eof())) {
           // cout << "index " << index << " field " << field << " ";
           // if(!str.empty()) {
                StoreInSOCStruct(soc, &node, field, str, index);
                //reseting values after newline and indexing array index
                //to move on to next value in soc array
                str = "";
                field = 0;
                //cout << "index " << index << "field " << field << endl;
                index++;
           // }
        } else {
            //add to string
            str = str + c;
        }
       // cout << "here while" << endl;
    } while(!infile.eof());
    //close file
    infile.close();
}

void queryPrompt(struct earnings array[]){
    //reading in 4 values from cin
    string query;
    getline(cin,query);
    if(query == ""){
        return;
    }
    string strArray[4];
    int i = 0;
    stringstream iss(query);
    while(i < 4){
        iss >> strArray[i];
        i++;
    }

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
        }else if((stoi(strArray[3]) < 1960) || (stoi(strArray[3]) > 2019)){
            cout << "Query failed."<< endl;
        }else{
            findRatio(array, stoi(strArray[2]), stoi(strArray[3]));
        }
        //checking if 2nd field is max
    }else if(strArray[1] == "max"){
        if((strArray[2] != "total") || (strArray[2] != "female") || (strArray[2] != "male")){
            cout << "Query failed." << endl;
        } else{
            cout << "Calling function" << endl;
        }
    }
}

//function for finding ratio
void findRatio(struct earnings array[], int year1, int year2){
    int yearSave1 = year1;
    int yearSave2 = year2;
    int index = (year1 - 1960);

    //check for invalid earnings
   while(year1 <= year2){
        if((array[index].female_earnings == 0) || (array[index].male_earnings == 0)){
            cout << "Query failed." << endl;
            return;
        }
        index++;
        year1++;
    }
    //for(int i = 0; i < 60; i++){
      //  cout << array[i].year << endl;
    //}

    int startIndex = 2019 - yearSave1;
    int endIndex = 2019 - yearSave2;
    cout << "The female-to-male earnings ratio for ";
    cout << to_string(yearSave1) << "-" ;
    cout << to_string(yearSave2) << ":" << endl;
    for(int i = startIndex ;i >= endIndex ;i--){
        float percent = ((float)array[i].female_earnings / (float)array[i].male_earnings) * (float)100;
        percent = percent - .05;
        cout << "\t" << array[i].year << ": " << fixed << setprecision(1) << percent << "%" << endl;
    }

}