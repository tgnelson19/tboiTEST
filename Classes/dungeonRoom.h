//
// Created by Tyler on 5/17/2021.
//

#ifndef TBOITEST_DUNGEONROOM_H
#define TBOITEST_DUNGEONROOM_H
#include <iostream>


class dungeonRoom {
public:
    dungeonRoom * above, * below, * left, * right;
    std::string roomType;

    dungeonRoom(){

    }

};


#endif //TBOITEST_DUNGEONROOM_H
