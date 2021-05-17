/// Main file

#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include "Classes/Entity.h"
#include "Classes/Character.h"
#include "Classes/Tear.h"

using namespace sf;

int main(){

    RenderWindow app(VideoMode(W, H), "tboiTEST"); /// Main Window
    app.setFramerateLimit(60);

    Texture pengyTex, backgnd;

    if (!pengyTex.loadFromFile("images/penguinCut.png")) { ///From Jay Ruzesky (@wolsenburg) Free to use under the Unsplash License
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }
    if (!backgnd.loadFromFile("images/tbioBackground.png")) {
        std::cout << "Error: Failed to load file" << std::endl;
        return EXIT_FAILURE;
    }

    Sprite penguin(pengyTex), background(backgnd);

    /// Game Variables

    float currShotSpeed = 9;

    std::list<Entity *> entities;
    penguin.setScale(0.3, 0.3);
    penguin.setOrigin(483, 362);

    Character *c = new Character();
    c->settings(penguin, 600, 600, 0);
    c->speed = 8;
    entities.push_back(c);

    penguin.setScale(0.1, 0.1);

    while (app.isOpen()){

        Event event;

        while (app.pollEvent(event)) {
            if (event.type == Event::Closed)
                app.close(); // When the window is closed, close everything

            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Left) { // When space is pressed
                    Tear *t = new Tear(); // Allocate memory for a new bullet
                    t->settings(penguin, c->x, c->y, 180); // Set it's angle to the angle you're facing
                    t->speed = currShotSpeed;
                    entities.push_back(t); // And put it into the entities list
                }
                else if (event.key.code == Keyboard::Right) { // When space is pressed
                    Tear *t = new Tear(); // Allocate memory for a new bullet
                    t->settings(penguin, c->x, c->y, 0); // Set it's angle to the angle you're facing
                    t->speed = currShotSpeed;
                    entities.push_back(t); // And put it into the entities list
                }
                else if (event.key.code == Keyboard::Up) { // When space is pressed
                    Tear *t = new Tear(); // Allocate memory for a new bullet
                    t->settings(penguin, c->x, c->y, 90); // Set it's angle to the angle you're facing
                    t->speed = currShotSpeed;
                    entities.push_back(t); // And put it into the entities list
                }
                else if (event.key.code == Keyboard::Down) { // When space is pressed
                    Tear *t = new Tear(); // Allocate memory for a new bullet
                    t->settings(penguin, c->x, c->y, 270); // Set it's angle to the angle you're facing
                    t->speed = currShotSpeed;
                    entities.push_back(t); // And put it into the entities list
                }
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
            if (!e->isAlive) {
                i = entities.erase(i); // if the entity life is false, remove it from the entities list
                delete e; // delete the object pointed to by e, polymorphism is used to call the proper destructor
            }
            else i++; // if life was true, move iterator to the next element in the list
        }

        app.draw(background);

        for (auto i:entities) { // For each entity
            i->draw(app); // Draw it
        }

        app.display(); // Display the drawn window to the window

    }

    return 0;
}