#ifndef STICK_H
#define STICK_H

#include "Point.h"

class Stick {
public:
    Stick();
    Stick(Point a, Point b);
    
    sf::Vector2f get_a();
    sf::Vector2f get_b();

    void draw(sf::RenderWindow *);

private:
    sf::Vector2f m_center, m_dir;
    float m_length;
};

#endif

