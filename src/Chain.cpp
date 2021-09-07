#include "Chain.h"

Chain::Chain()
{
    for (int i=0; i<SIZE; i++) {
        m_pts.push_back(Point(i*100, i*i*3));
    }
    for (int i=0; i<SIZE-1; i++) {
        m_sticks.push_back(Stick(&m_pts[i], &m_pts[i+1]));
    }
}

int Chain::find_point(int x, int y)
{
    int i = -1;
    for (int k=0; k<m_pts.size(); k++)
    {
        if (m_pts[k].is_clicked(x, y))
        {
            i = k;
        }
    }
    return i;
}

void Chain::set_lock(int id, bool locked)
{
    m_pts[id].set_lock(locked);
}

void Chain::add_pt(Point pt)
{
    m_pts.push_back(pt);
}

void Chain::update(float deltaTime)
{
    for (int i=0; i<m_pts.size(); i++)
    {
        m_pts[i].update(deltaTime);
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
    for (Point pt : m_pts) {
        pt.draw(p_window);
    }
    for (Stick stick : m_sticks) {
        stick.draw(p_window);
    }
}
