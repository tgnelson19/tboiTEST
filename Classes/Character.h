//
// Created by Tyler on 5/17/2021.
//

#ifndef TBOITEST_CHARACTER_H
#define TBOITEST_CHARACTER_H
#include "Entity.h"
#include <cmath>

const int W = 1500;
const int H = 900;

class Character : public Entity {
public:
    Character(){ name = "character"; }

    void update() {
        x += speed*cos(angle);
        y += speed*sin(angle);

        if(x > W) x = W;
        if(x < 0) x = 0;
        if(y > H) y = H;
        if(y < 0) y = 0;
    }

};


#endif //TBOITEST_CHARACTER_H
