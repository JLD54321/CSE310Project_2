//
// Created by cse310 on 2/28/22.
#ifndef PROJECT2_JOSH_DEES_UTILITY_H
#define PROJECT2_JOSH_DEES_UTILITY_H
#include "defns.h"
#include <string>

using namespace std;

void ReadInEarnings(struct earnings *earningsArray);
void ReadInOccupation(int year, struct SOC *socArray);
void StoreInSOCStruct(struct SOC *soc, struct SOC *tempSoc, int fieldNum, string fieldVal, int socIndex);
void StoreInEarningsStruct(struct earnings *Data,struct earnings *node,int field, string str, int index);
void queryPrompt(struct earnings *earningsArray);
void findRatio(struct earnings *earningsArray, int year1, int year2);

#endif //PROJECT2_JOSH_DEES_UTILITY_H
