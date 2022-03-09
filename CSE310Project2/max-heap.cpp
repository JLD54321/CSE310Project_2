//
// Created by cse310 on 2/23/22.
//
#include <iostream>
#include <fstream>
#include "math.h"
#include "max-heap.h"

using namespace std;

//Max_heapifySOC function to max heap the SOC array
void Max_heapifySOCTotal(struct SOC soc[], int i, int size){
    //soc stores the max heap
    //i is the position violating max heap
    //size is the size of the heap

    //defining left and right indexes based on the position "i"
    //and initializing the largest index
    int l = 2 * i;
    int r = (2 * i) + 1;
    int largest = i;
    struct SOC temp;
    //if the largest index is less than or equal to size
    //and value of largest node total is greater than
    if((l <= size) && (soc[l].total > soc[i].total)){
        largest = l;
    }
    if((r <= size) && (soc[r].total > soc[largest].total)){
        largest = r;
    }
    if(largest != i){
        temp = soc[largest];
        soc[largest] = soc[i];
        soc[i] = temp;
        Max_heapifySOCTotal(soc,largest,size);
    }
}

void BUILD_MAX_HEAP_SOCTotal(struct SOC soc[], int size){
    //ofstream outfile;
    //outfile.open("Occupation-Dist-All-1999");

    for(int i = floor(size/2); i >= 0; i--){
        Max_heapifySOCTotal(soc,i,size);
    }
   // for (int i = 0; i <= NUM_OCC; i++){

     //   outfile << soc[i].total << endl;
    //}
    //outfile.close();
    //cout << endl;
}

//Max_heapifySOC function to max heap the SOC array
void Max_heapifySOCFemale(struct SOC soc[], int i, int size){
    //soc stores the max heap
    //i is the position violating max heap
    //size is the size of the heap

    //defining left and right indexes based on the position "i"
    //and initializing the largest index
    int l = 2 * i;
    int r = (2 * i) + 1;
    int largest = i;
    struct SOC temp;
    //if the largest index is less than or equal to size
    //and value of largest node total is greater than
    if((l <= size) && (soc[l].female > soc[i].female)){
        largest = l;
    }
    if((r <= size) && (soc[r].female > soc[largest].female)){
        largest = r;
    }
    if(largest != i){
        temp = soc[largest];
        soc[largest] = soc[i];
        soc[i] = temp;
        Max_heapifySOCTotal(soc,largest,size);
    }
}

//Max_heapifySOC function to max heap the SOC array
void Max_heapifySOCMale(struct SOC soc[], int i, int size){
    //soc stores the max heap
    //i is the position violating max heap
    //size is the size of the heap

    //defining left and right indexes based on the position "i"
    //and initializing the largest index
    int l = 2 * i;
    int r = (2 * i) + 1;
    int largest = i;
    struct SOC temp;
    //if the largest index is less than or equal to size
    //and value of largest node total is greater than
    if((l <= size) && (soc[l].male > soc[i].male)){
        largest = l;
    }
    if((r <= size) && (soc[r].male > soc[largest].male)){
        largest = r;
    }
    if(largest != i){
        temp = soc[largest];
        soc[largest] = soc[i];
        soc[i] = temp;
        Max_heapifySOCTotal(soc,largest,size);
    }
}

void BUILD_MAX_HEAP_SOCFemale(struct SOC soc[], int size) {
    //ofstream outfile;
    //outfile.open("Female_Earnings");

    for (int i = floor(size / 2); i >= 0; i--) {
        Max_heapifySOCFemale(soc, i, size);
    }

    //for (int i = 0; i <= NUM_OCC; i++){
    //outfile << soc[i].female << endl;
    //}
    //outfile.close();
}

void BUILD_MAX_HEAP_SOCMale(struct SOC soc[], int size) {
    for (int i = floor(size / 2); i >= 0; i--) {
        Max_heapifySOCMale(soc, i, size);
    }
}