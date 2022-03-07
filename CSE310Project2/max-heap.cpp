//
// Created by cse310 on 2/23/22.
//
#include <iostream>
#include "math.h"
#include "max-heap.h"

using namespace std;

//Max_heapifySOC function to max heap the SOC array
void Max_heapifySOC(struct SOC soc[], int i, int size){
    //defining left and right indexes based on the position "i"
    //and initializing the largest index
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest;
    cout << l << " " << r << " " << largest;
    struct SOC temp;
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
        cout << "Heapifying" << endl;
        Max_heapifySOC(soc,largest,size);
    }
}

void BUILD_MAX_HEAP_SOC(struct SOC soc[], int size){
    for(int i = floor(size/2); i >= 1; i--){
        Max_heapifySOC(soc,i,size);
    }
}
void Max_heapifyEarnings(){

}

