#ifndef POINT_H
#define POINT_H

#include <SFML/Graphics.hpp>

static float const gravity = 200;

class Point {
public:
    Point();
    Point(int x, int y);

    sf::Vector2f get_pos();
    void set_pos(sf::Vector2f pos);
    bool is_locked();

    void lock();
    void update(float deltaTime);
    void draw(sf::RenderWindow *);

private:
    sf::Vector2f m_pos;
    sf::Vector2f m_velocity;
    bool m_locked;
};

#endif
