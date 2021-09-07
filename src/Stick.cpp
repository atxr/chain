#include "Stick.h"
#include <math.h>
#include <iostream>

float norm(sf::Vector2f v) { return sqrt(v.x*v.x + v.y*v.y); }
sf::Vector2f normalize(sf::Vector2f v) { return v / norm(v); }

Stick::Stick() : Stick(NULL, NULL) {}
Stick::Stick(Point *a, Point *b) : a(a), b(b)
{ 
    if (a != NULL && b != NULL)
    {
        m_length = norm(b->get_pos() - a->get_pos());
    }
}

sf::Vector2f Stick::get_center() { return (a->get_pos() + b->get_pos()) / 2.f ; }
sf::Vector2f Stick::get_dir() { return normalize(b->get_pos() - a->get_pos()); }

void Stick::update()
{
    if (!a->is_locked())
    {
        a->set_pos(get_center() - m_length*get_dir()/2.f);
    }
    if (!b->is_locked())
    {
        b->set_pos(get_center() + m_length*get_dir()/2.f);
    }
}

void Stick::draw(sf::RenderWindow * p_window)
{
    sf::Vertex line[2] = {sf::Vertex(a->get_pos()), sf::Vertex(b->get_pos())};
    p_window->draw(line, 2, sf::Lines);
}

