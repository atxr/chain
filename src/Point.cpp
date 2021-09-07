#include "Point.h"
#include <iostream>

Point::Point() : Point(0, 0) {}

Point::Point(int x, int y) : 
    m_pos(sf::Vector2f((float) x, (float) y)), 
    m_velocity(sf::Vector2f(0, 0)),
    m_locked(false) { std::cout << (float) x << std::endl; }

void Point::lock() { m_locked = true; }

sf::Vector2f Point::get_pos() { return m_pos; }

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
    circle.setOrigin(5,5);
    circle.setPosition(m_pos);
    p_window->draw(circle);
}
