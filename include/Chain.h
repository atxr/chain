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
    void add_pt(Point pt);

    private:
    std::vector<Stick> m_sticks;
    std::vector<Point> m_pts;
};

#endif
