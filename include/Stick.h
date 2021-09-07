#ifndef STICK_H
#define STICK_H

#include "Point.h"

class Stick {
public:
    Stick();
    Stick(Point *a, Point *b);
    
    sf::Vector2f get_center();
    sf::Vector2f get_dir();

    void update();
    void draw(sf::RenderWindow *);

private:
    Point *a;
    Point *b;
    float m_length;
};

#endif

