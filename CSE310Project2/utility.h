//
// Created by cse310 on 2/28/22.
#ifndef PROJECT2_JOSH_DEES_UTILITY_H
#define PROJECT2_JOSH_DEES_UTILITY_H
#include "defns.h"
#include <string>

using namespace std;

void ReadInEarnings(struct earnings *earningsArray);
void ReadInOccupation(int year, struct SOC *socArray);
void StoreInSOCStruct(struct SOC *socArray, int fieldNum, char *fieldVal, int socIndex);
void StoreInEarningsStruct(struct earnings *earningsArray, int field, string str, int index);
void queryPrompt(earnings *earningsArray, SOC *socArray, string year);
void findRatio(struct earnings *earningsArray, int year1, int year2);
void findMax(SOC *socArray, string workerType, int year, int size);

#endif //PROJECT2_JOSH_DEES_UTILITY_H
