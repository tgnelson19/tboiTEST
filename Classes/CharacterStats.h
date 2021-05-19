//
// Created by Tyler on 5/17/2021.
//

#ifndef TBOITEST_CHARACTERSTATS_H
#define TBOITEST_CHARACTERSTATS_H
#include "TearStats.h"


class CharacterStats {
public:
    float moveSpeed, tearDelay;
    TearStats currts;

    CharacterStats(){}

    void setCharStats(float ms, float td){ moveSpeed = ms; tearDelay = td; }

};


#endif //TBOITEST_CHARACTERSTATS_H
