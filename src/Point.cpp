#include "Point.h"
#include <iostream>

Point::Point(int x, int y) : 
    m_pos(sf::Vector2f((float) x, (float) y)), 
    m_velocity(sf::Vector2f(0, 0)),
    m_locked(false) {}

void Point::lock() { m_locked = true; }

void Point::update(float deltaTime)
{
    if (!m_locked)
    {
        // point velocity
        sf::Vector2f tmp = m_pos;
        m_pos += m_velocity;
        // gravity
        m_pos += gravity * deltaTime * deltaTime * sf::Vector2f(0, 1);

        // update velocity
        m_velocity = m_pos - tmp;

    }
}

void Point::draw(sf::RenderWindow *p_window)
{
    sf::CircleShape circle = sf::CircleShape(10);
    circle.setPosition(m_pos);
    p_window->draw(circle);
}
