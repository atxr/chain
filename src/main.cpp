#include <iostream>
#include "Point.h"
#include "Stick.h"
#include "Chain.h"
#include <random>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 600), "sfml-app");
    
    // Build points and sticks
    Chain chain;
    chain.set_lock(0, true);
    chain.set_lock(5, true);

    bool pause = true;
    int mode = 0;

    sf::Clock deltaClock;
    float deltaTime(0.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type) { 
                case(sf::Event::Closed):
                    window.close();
                    break;

                case(sf::Event::MouseButtonPressed):
                    switch(event.mouseButton.button) {
                        case (sf::Mouse::Left):
                            switch (mode) {
                                case(0):
                                    chain.add_pt(Point(event.mouseButton.x, event.mouseButton.y));
                                    break;
                                case(1): {
                                    // lock the selected Point
                                    int id = chain.find_point(event.mouseButton.x, event.mouseButton.y);
                                    if (id != -1) {
                                        cout << "ok" << endl;
                                        chain.set_lock(id, true);
                                    }
                                    break; 
                                    }
                                default:
                                    // add stick
                                    break;
                            }
                            break;

                        case(sf::Mouse::Right):
                            switch (mode) {
                                case(0):
                                    // delete a point
                                    break;
                                case(1): {
                                    // unlock the selected Point
                                    int id = chain.find_point(event.mouseButton.x, event.mouseButton.y);
                                    if (id != -1) {
                                        chain.set_lock(id, false);
                                    }
                                    break;
                                    }
                                default:
                                    // remove stick
                                    break;
                            }
                            break;

                        default:
                            break;
                    }
                    break;

                case (sf::Event::KeyPressed):
                    switch (event.key.code) {
                        case (sf::Keyboard::Space):
                            pause = !pause;
                            break;
                        case (sf::Keyboard::LControl):
                            mode = (mode + 1) % 3;
                            break;
                        default:
                            break;
                    }
                    break;

                default:
                    break;
            }
        }

        window.clear();
        
        if (!pause) {
            chain.update(deltaTime);
        }
        chain.draw(&window);

        window.display();

        // update deltaTime
        deltaTime = deltaClock.restart().asMicroseconds() * 1e-6;
    }

    return 0;
}

