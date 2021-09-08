#include "Chain.h"

Chain::Chain() {}
Chain::Chain(int m, int n)
{
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            m_pts.push_back(new Point(100 + i*1000/m, 50 + j*500/n));
        }
    }
    for (int i=0; i<m-1; i++) {
        for (int j=0; j<n; j++) {
            m_sticks.push_back(new Stick(m_pts[i*n + j], m_pts[(i+1)*n + j]));
        }
    }
    for (int j=0; j<n-1; j++) {
        for (int i=0; i<m; i++) {
            m_sticks.push_back(new Stick(m_pts[i*n + j], m_pts[i*n + j+1]));
        }
    }

    for (int i=0; i<m; i+=2) {
        m_pts[i*n]->set_lock(true);
    }
}

int Chain::find_point(int x, int y)
{
    int i = -1;
    for (int k=0; k<m_pts.size(); k++)
    {
        if (m_pts[k]->is_clicked(x, y))
        {
            i = k;
        }
    }
    return i;
}

void Chain::set_lock(int id, bool locked)
{
    m_pts[id]->set_lock(locked);
}

void Chain::add_pt(Point pt)
{
    // TODO check if not redondant point
    m_pts.push_back(&pt);
}

void Chain::add_stick(int id1, int id2)
{
    // TODO check if not redondant stick
    m_sticks.push_back(new Stick(m_pts[id1], m_pts[id2]));
}

void Chain::update(float deltaTime)
{
    for (int i=0; i<m_pts.size(); i++)
    {
        m_pts[i]->update(deltaTime);
    }

    for (int k=0; k<N_ITER; k++)
    {
        for (int i=0; i<m_sticks.size(); i++)
        {
            m_sticks[i]->update();
        }
    }
}   

void Chain::draw(sf::RenderWindow *p_window)
{
    for (int i=0; i<m_pts.size(); i++) {
        m_pts[i]->draw(p_window);
    }
    for (int i=0; i<m_sticks.size(); i++) {
        m_sticks[i]->draw(p_window);
    }
}
