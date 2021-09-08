#ifndef CHAIN_H
#define CHAIN_H

#include "Point.h"
#include "Stick.h"

static int const SIZE = 10;
static int const N_ITER = 5;

class Chain {
    public:    
    Chain();

    int find_point(int x, int y);
    void update(float deltaTime);
    void draw(sf::RenderWindow *);
    void set_lock(int id, bool locked);
    void add_pt(Point pt);
    void add_stick(int id1, int id2);

    private:
    std::vector<Stick> m_sticks;
    std::vector<Point> m_pts;
};

#endif
