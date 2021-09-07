#include "Chain.h"

Chain::Chain()
{
    for (int i=0; i<SIZE; i++)
    {
        m_pts[i] = Point(30+i*100, i*i*3);
    }
    for (int i=0; i<SIZE-1; i++)
    {
        m_sticks[i] = Stick(m_pts[i], m_pts[i+1]);
    }
}

void Chain::update(float deltaTime)
{
    for (int i=0; i<SIZE; i++)
    {
        m_pts[i].update(deltaTime);
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