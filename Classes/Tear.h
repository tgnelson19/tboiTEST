//
// Created by Tyler on 5/17/2021.
//

#ifndef TBOITEST_TEAR_H
#define TBOITEST_TEAR_H
#include "Entity.h"

class Tear : public Entity{
public:
    Tear() {
        name = "tear";
    }

    void update() {
        x += speed * cos(dtr*angle);
        y -= speed * sin(dtr*angle);

        if (x > W || x < 0 || y > H || y < 0) {
            isAlive = false; // If it hits a wall, kills the bullet
        }
    }

};

#endif //TBOITEST_TEAR_H
