//
// Created by Tyler on 5/17/2021.
//

#ifndef TBOITEST_ENTITY_H
#define TBOITEST_ENTITY_H
#include <SFML/Graphics.hpp>
#include <cmath>

class Entity {
protected:
    float x, y; /// Position on the screen
    float speed, angle; /// Speed of an entity will be based off of POLAR coordinate system, not cartesian
    bool isAlive; /// Determines if entity is alive
    std::string name; /// Determines which entity it is
    sf::Sprite sprite; /// Gives the entity a sprite

public:
    Entity() { isAlive = true }; /// Default Constructor

    void settings(sf::Sprite &s, float X, float Y, float Angle) { sprite = s; x = X; y = Y; angle = Angle; } /// Changes Settings

    virtual void update() {}; /// Used for future derived classes

    void draw(sf::RenderWindow &app){ /// Draws current entity to the screen
        sprite.setPosition(x,y);
        sprite.setRotation(angle + 90);
        app.draw(sprite);
    }

    virtual ~Entity() {}; /// Used for future derived classes

};

#endif //TBOITEST_ENTITY_H
