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
    RenderWindow app(VideoMode(W, H), "tboiTEST"); /// Main Window
    app.setFramerateLimit(60);

    Texture pengyTex, backgnd, openDoor;
    if (!pengyTex.loadFromFile("images/penguinCut.png")) { ///From Jay Ruzesky (@wolsenburg) Free to use under the Unsplash License
        std::cout << "Error: Failed to load file" << std::endl; return EXIT_FAILURE; }
    if (!backgnd.loadFromFile("images/tbioBackground.png")) { std::cout << "Error: Failed to load file" << std::endl; return EXIT_FAILURE; }
    if (!openDoor.loadFromFile("images/openDoor.png")) { std::cout << "Error: Failed to load file" << std::endl; return EXIT_FAILURE; }
    Sprite penguin(pengyTex), background(backgnd), door(openDoor);

    CharacterStats stats; /// Game Variables
    stats.currts.shotSpeed = 9;
    stats.currts.damage = 1;
    stats.currts.range = 20;

    std::list<Entity *> entities;
    penguin.setScale(0.3, 0.3);
    penguin.setOrigin(483, 362);

    Character *c = new Character();
    c->settings(penguin, 600, 600, 0); c->speed = 8;
    entities.push_back(c);

    penguin.setScale(0.1, 0.1);

    while (app.isOpen()){
        Event event;
        while (app.pollEvent(event)) {
            if (event.type == Event::Closed){ app.close();}
            if (event.type == Event::KeyPressed) {
                Tear *t = new Tear();
                if (event.key.code == Keyboard::Left) {t->settings(penguin, c->x, c->y, 180);}
                else if (event.key.code == Keyboard::Right) {t->settings(penguin, c->x, c->y, 0);}
                else if (event.key.code == Keyboard::Up) {t->settings(penguin, c->x, c->y, 90);}
                else if (event.key.code == Keyboard::Down) {t->settings(penguin, c->x, c->y, 270);}
                t->tts = stats.currts;
                entities.push_back(t);
            }
        }
        c->isMoving = false; c->dx = 0; c->dy = 0;
        if (Keyboard::isKeyPressed(Keyboard::D)) { c->isMoving = true; c->dx = 1; }
        else if (Keyboard::isKeyPressed(Keyboard::A)) { c->isMoving = true; c->dx = -1; }
        if (Keyboard::isKeyPressed(Keyboard::W)) { c->isMoving = true; c->dy = 1; }
        else if (Keyboard::isKeyPressed(Keyboard::S)) { c->isMoving = true; c->dy = -1; }

        for (auto i = entities.begin(); i != entities.end();) {
            Entity *e = *i; //*i is an Entity pointer, using * on an iterator returns the element from the list
            e->update(); // Uses polymorphism to call the proper update method
            if (!e->isAlive) { i = entities.erase(i); delete e; }
            else i++; // if life was true, move iterator to the next element in the list
        }
        app.draw(background);
        for (auto i:entities) {i->draw(app);}
        app.display();
    }
    return 0;
}