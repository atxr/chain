#include "Chain.h"

Chain::Chain()
{
    for (int i=0; i<SIZE; i++) {
        m_pts.push_back(Point(30+i*100, i*i*3));
    }
    for (int i=0; i<SIZE-1; i++) {
        m_sticks.push_back(Stick(&m_pts[i], &m_pts[i+1]));
    }
}

void Chain::lock(int id)
{
    m_pts[id].lock();
}

void Chain::add_pt(Point pt)
{
    m_pts.push_back(pt);
}

void Chain::update(float deltaTime)
{
    for (Point pt: m_pts)
    {
        pt.update(deltaTime);
    }

    for (int k=0; k<N_ITER; k++)
    {
        for (Stick stick: m_sticks)
        {
            stick.update();
        }
    }
}   

void Chain::draw(sf::RenderWindow *p_window)
{
    for (int i=0; i<SIZE; i++) {
        m_pts[i].draw(p_window);
    }
    for (int i=0; i<SIZE-1; i++) {
        m_sticks[i].draw(p_window);
    }
}
