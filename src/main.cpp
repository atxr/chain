#include <iostream>
#include "Point.h"
#include "Stick.h"
#include <random>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 600), "sfml-app");
    
    // Build points and sticks
    int const n_pts = 10;
    Point pts[n_pts];
    Stick sticks[n_pts - 1];
    for (int i=0; i<n_pts; i++)
    {
        pts[i] = Point(30+i*100, i*i*3);
    }
    for (int i=0; i<n_pts-1; i++)
    {
        sticks[i] = Stick(pts[i], pts[i+1]);
    }

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
        
        for (int i=0; i<n_pts; i++)
        {
            pts[i].update(deltaTime);
            pts[i].draw(&window);

            if(i != 0)
            {
                sticks[i-1].draw(&window);
            }
        }
        sticks[0].draw(&window);

        window.display();

        // update deltaTime
        deltaTime = deltaClock.restart().asMicroseconds() * 1e-6;
    }

    return 0;
}

