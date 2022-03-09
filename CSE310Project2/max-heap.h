//
// Created by cse310 on 3/6/22.
//
#ifndef PROJECT2_JOSH_DEES_MAX_HEAP_H
#define PROJECT2_JOSH_DEES_MAX_HEAP_H
#include "defns.h"

using namespace std;

void Max_heapifySOCTotal(struct SOC *soc,int i, int size);
void Max_heapifySOCMale(struct SOC *soc,int i, int size);
void Max_heapifySOCFemale(struct SOC *soc,int i, int size);
void BUILD_MAX_HEAP_SOCTotal(struct SOC *soc, int size);
void BUILD_MAX_HEAP_SOCMale(struct SOC *soc, int size);
void BUILD_MAX_HEAP_SOCFemale(struct SOC *soc, int size);

#endif //PROJECT2_JOSH_DEES_MAX_HEAP_H
