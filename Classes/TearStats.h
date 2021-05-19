//
// Created by Tyler on 5/17/2021.
//

#ifndef TBOITEST_TEARSTATS_H
#define TBOITEST_TEARSTATS_H


class TearStats {
public:
    float shotSpeed, damage, range;

    TearStats(){}

    void setTearStats(float ss, float d, float r){ shotSpeed = ss; damage = d; range = r; }

};


#endif //TBOITEST_TEARSTATS_H
