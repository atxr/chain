#include "Point.h"
#include <iostream>


float norm(sf::Vector2f v) { return sqrt(v.x*v.x + v.y*v.y); }
sf::Vector2f normalize(sf::Vector2f v) { return v / norm(v); }

Point::Point() : Point(0, 0) {}

Point::Point(int x, int y) : 
    m_pos(sf::Vector2f((float) x, (float) y)), 
    m_prev_pos(m_pos),
    m_locked(false) {}

void Point::set_lock(bool locked) { m_locked = locked; }

sf::Vector2f Point::get_pos() { return m_pos; }
void Point::set_pos(sf::Vector2f pos) { m_pos = pos; }
bool Point::is_locked() { return m_locked; }

bool Point::is_clicked(int x, int y)
{
    return (norm(sf::Vector2f(x,y) - get_pos()) < PT_RANGE);
}

void Point::update(float deltaTime)
{
    sf::Vector2f tmp = m_pos;
    if (!m_locked)
    {
        float alpha = (float) (1 - 1e-4);
        m_pos += (m_pos - m_prev_pos) * alpha;
        // gravity
        //m_pos += gravity * deltaTime * deltaTime * sf::Vector2f(0, 1);
        m_pos += (float) 9e-4 * sf::Vector2f(0, 1);
    }
    
    // update previous position
    m_prev_pos = tmp;
}

void Point::draw(sf::RenderWindow *p_window)
{
    sf::CircleShape circle = sf::CircleShape(PT_RANGE);
    circle.setOrigin(PT_RANGE, PT_RANGE);
    circle.setPosition(m_pos);
    if (m_locked)
    {
        circle.setFillColor(sf::Color::Red);
    }
    p_window->draw(circle);

    sf::Vertex vel[2] = {sf::Vertex(m_pos), sf::Vertex(m_pos + 100.f*(m_pos - m_prev_pos))};
    p_window->draw(vel, 2, sf::Lines);
}
