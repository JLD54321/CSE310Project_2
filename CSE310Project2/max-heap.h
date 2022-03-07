//
// Created by cse310 on 3/6/22.
//
#ifndef PROJECT2_JOSH_DEES_MAX_HEAP_H
#define PROJECT2_JOSH_DEES_MAX_HEAP_H
#include "defns.h"

using namespace std;

void Max_heapifySOC(struct SOC *soc,int i, int size);
void Max_heapifyEarnings(struct earnings *data, int i, int size);
void BUILD_MAX_HEAP_SOC(struct SOC *soc, int size);

#endif //PROJECT2_JOSH_DEES_MAX_HEAP_H
