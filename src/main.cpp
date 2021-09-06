#include <iostream>
#include "Point.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 600), "sfml-app");
    Point pt1 = Point(200, 200);
    Point pt3 = Point(800, 100);

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
        
        pt1.update(deltaTime);
        pt3.update(deltaTime);

        pt1.draw(&window);
        pt3.draw(&window);

        window.display();

        // update deltaTime
        deltaTime = deltaClock.restart().asMicroseconds() * 1e-6;
    }

    return 0;
}

