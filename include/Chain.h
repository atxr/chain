#ifndef CHAIN_H
#define CHAIN_H

#include "Point.h"
#include "Stick.h"

static int const SIZE = 10;
static int const N_ITER = 100;

class Chain {
    public:    
    Chain();

    void update(float deltaTime);
    void draw(sf::RenderWindow *);
    void lock(int id);

    private:
    Stick m_sticks[SIZE-1];
    Point m_pts[SIZE];
};

#endif
