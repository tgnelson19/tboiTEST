//
// Created by Tyler on 5/17/2021.
//

#ifndef TBOITEST_TEAR_H
#define TBOITEST_TEAR_H
#include "Entity.h"

const int W = 1500;
const int H = 900;

class Tear : public Entity{
    Tear() {
        name = "tear";
    }

    void update() {
        x += speed * cos(angle);
        y += speed * sin(angle);

        if (x > W || x < 0 || y > H || y < 0) {
            isAlive = false; // If it hits a wall, kills the bullet
        }
    }


};


#endif //TBOITEST_TEAR_H
