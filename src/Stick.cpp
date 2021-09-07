#include "Stick.h"
#include <math.h>
#include <iostream>

float norm(sf::Vector2f v) { return sqrt(v.x*v.x + v.y*v.y); }
sf::Vector2f normalize(sf::Vector2f v) { return v / norm(v); }

Stick::Stick() : Stick(Point(), Point()) {}
Stick::Stick(Point a, Point b) : 
    m_center((a.get_pos() + b.get_pos()) / 2.f),
    m_dir(normalize(b.get_pos() - a.get_pos())),
    m_length(norm(b.get_pos() - a.get_pos())) {}

sf::Vector2f Stick::get_a() { return m_center - m_length*m_dir / 2.f; }
sf::Vector2f Stick::get_b() { return m_center + m_length*m_dir / 2.f; }

void Stick::draw(sf::RenderWindow * p_window)
{
    sf::Vertex line[2] = {sf::Vertex(get_a()), sf::Vertex(get_b())};
    p_window->draw(line, 2, sf::Lines);
}

