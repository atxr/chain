#ifndef CHAIN_H
#define CHAIN_H

#include "Point.h"
#include "Stick.h"

static int const SIZE = 10;

class Chain {
    public:    
    Chain();

    void update(float deltaTime);
    void draw(sf::RenderWindow *);

    private:
    Stick m_sticks[SIZE-1];
    Point m_pts[SIZE];
};

#endif
