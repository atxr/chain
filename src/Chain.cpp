#include "Chain.h"

Chain::Chain() 
{
    //pendule with mass
    m_pts.push_back(new Point(600, 200));
    m_pts.push_back(new Point(500, 200));
    m_pts.push_back(new Point(400, 200));
    
    m_pts.push_back(new Point(300, 200));
    m_pts.push_back(new Point(200, 200));
    m_pts.push_back(new Point(250, 150));
    m_pts.push_back(new Point(250, 250));

    m_pts[0]->set_lock(true);

    m_sticks.push_back(new Stick(m_pts[0], m_pts[1]));
    m_sticks.push_back(new Stick(m_pts[1], m_pts[2]));
    m_sticks.push_back(new Stick(m_pts[2], m_pts[3]));
    m_sticks.push_back(new Stick(m_pts[3], m_pts[4]));
    m_sticks.push_back(new Stick(m_pts[3], m_pts[5]));
    m_sticks.push_back(new Stick(m_pts[3], m_pts[6]));
    m_sticks.push_back(new Stick(m_pts[4], m_pts[5]));
    m_sticks.push_back(new Stick(m_pts[4], m_pts[6]));

    //double pendule
    m_pts.push_back(new Point(1000, 200));
    m_pts.push_back(new Point(1075, 200));
    m_pts.push_back(new Point(1150, 200));

    m_pts[7]->set_lock(true);

    m_sticks.push_back(new Stick(m_pts[7], m_pts[8]));
    m_sticks.push_back(new Stick(m_pts[9], m_pts[8]));
}

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

void Chain::add_pt(Point *pt)
{
    // TODO check if not redondant point
    m_pts.push_back(pt);
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
