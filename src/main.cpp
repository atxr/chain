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

    sf::Clock deltaClock;
    float deltaTime(0.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        chain.update(deltaTime);
        chain.draw(&window);

        window.display();

        // update deltaTime
        deltaTime = deltaClock.restart().asMicroseconds() * 1e-6;
    }

    return 0;
}

