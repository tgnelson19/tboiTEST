/// Made by Tyler Nelson
/// Date : May 17th 2021
/// tboiTEST

#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include "Classes/CharacterStats.h"
#include "Classes/Entity.h"
#include "Classes/Character.h"
#include "Classes/Tear.h"

using namespace sf;

int main(){

    /// Main Window

    RenderWindow app(VideoMode(W, H), "tboiTEST");
    app.setFramerateLimit(60);

    /// Loading in textures and sprites

    Texture pengyTex, backgnd, openDoor;
    if (!pengyTex.loadFromFile("images/penguinCut.png")) { ///From Jay Ruzesky (@wolsenburg) Free to use under the Unsplash License
        std::cout << "Error: Failed to load file" << std::endl; return EXIT_FAILURE; }
    if (!backgnd.loadFromFile("images/tbioBackground.png")) { std::cout << "Error: Failed to load file" << std::endl; return EXIT_FAILURE; }
    if (!openDoor.loadFromFile("images/openDoor.png")) { std::cout << "Error: Failed to load file" << std::endl; return EXIT_FAILURE; }
    Sprite penguin(pengyTex), background(backgnd), door(openDoor);
    penguin.setScale(0.25, 0.25);
    penguin.setOrigin(483, 362);
    door.setOrigin(55,0); door.setScale(0.9,0.8);

    /// Entity List

    std::list<Entity *> entities;

    ///Door creation

    Entity *ud = new Entity(); ud->settings(door, W/2, 0, 0); entities.push_back(ud);
    door.setRotation(180); Entity *dd = new Entity(); dd->settings(door, W/2, H, 0); entities.push_back(dd);
    door.setScale(0.9, 0.7);
    door.setRotation(90); Entity *rd = new Entity(); rd->settings(door, W, H/2, 0); entities.push_back(rd);
    door.setRotation(270); Entity *ld = new Entity(); ld->settings(door, 0, H/2, 0); entities.push_back(ld);
    ud->name = "upDoor"; dd->name = "downDoor"; rd->name = "rightDoor"; ld->name = "leftDoor";

    /// Character creation

    Character *c = new Character();
    c->settings(penguin, 600, 600, 0);
    entities.push_back(c);

    /// Game Variables

    CharacterStats stats;
    stats.setCharStats(8, 0.2); c->speed = stats.moveSpeed;
    stats.currts.setTearStats(9,1,20);

    Clock reloadClock;
    float timeCounter = 0;

    penguin.setScale(0.1, 0.1); /// Making penguin smaller for projectiles

    while (app.isOpen()){

        /// Tear Delay Logic

        float timer = reloadClock.getElapsedTime().asSeconds();
        reloadClock.restart();
        timeCounter += timer;

        /// Close Logic

        Event event;
        while (app.pollEvent(event)) { if (event.type == Event::Closed){ app.close();} }

        ///Shot Logic

        if(timeCounter > stats.tearDelay) {
            Tear *t = new Tear();
            if (Keyboard::isKeyPressed(Keyboard::Left)) { t->settings(penguin, c->x, c->y, 180); }
            else if (Keyboard::isKeyPressed(Keyboard::Right)) { t->settings(penguin, c->x, c->y, 0); }
            else if (Keyboard::isKeyPressed(Keyboard::Up)) { t->settings(penguin, c->x, c->y, 90); }
            else if (Keyboard::isKeyPressed(Keyboard::Down)) { t->settings(penguin, c->x, c->y, 270); }
            t->tts = stats.currts; entities.push_back(t); timeCounter = 0;
        }

        ///Movement Logic

        c->isMoving = false; c->dx = 0; c->dy = 0;
        if (Keyboard::isKeyPressed(Keyboard::D)) { c->isMoving = true; c->dx = 1; }
        else if (Keyboard::isKeyPressed(Keyboard::A)) { c->isMoving = true; c->dx = -1; }
        if (Keyboard::isKeyPressed(Keyboard::W)) { c->isMoving = true; c->dy = 1; }
        else if (Keyboard::isKeyPressed(Keyboard::S)) { c->isMoving = true; c->dy = -1; }

        ///Collision Logic

        for (auto i = entities.begin(); i != entities.end();) {
            std::list<FloatRect> hitBoxes;

        }









        ///Update Logic

        for (auto i = entities.begin(); i != entities.end();) {
            Entity *e = *i; //*i is an Entity pointer, using * on an iterator returns the element from the list
            e->update(); // Uses polymorphism to call the proper update method
            if (!e->isAlive) { i = entities.erase(i); delete e; }
            else i++; // if life was true, move iterator to the next element in the list
        }

        ///Draw Logic

        app.draw(background);
        for (auto i:entities) {i->draw(app);}
        app.display();

    }
    return 0;
}