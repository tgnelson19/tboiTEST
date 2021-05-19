//
// Created by Tyler on 5/17/2021.
//

#ifndef TBOITEST_TEAR_H
#define TBOITEST_TEAR_H
#include "Entity.h"
#include "TearStats.h"

class Tear : public Entity{
public:

    TearStats tts;

    Tear() { name = "tear"; }

    void update() {
        x += tts.shotSpeed * cos(dtr*angle);
        y -= tts.shotSpeed * sin(dtr*angle);

        if (x > W || x < 0 || y > H || y < 0) {
            isAlive = false; // If it hits a wall, kills the bullet
        }
    }

};

#endif //TBOITEST_TEAR_H
