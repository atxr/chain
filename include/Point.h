#ifndef POINT_H
#define POINT_H

#include <SFML/Graphics.hpp>
#include <math.h>

static float const gravity = 1000;
static float const PT_RANGE = 8;

float norm(sf::Vector2f);
sf::Vector2f normalize(sf::Vector2f);

class Point {
public:
    Point();
    Point(int x, int y);

    sf::Vector2f get_pos();
    void set_pos(sf::Vector2f pos);
    void set_lock(bool locked);
    bool is_locked();

    bool is_clicked(int mouseX, int mouseY);
    void update(float deltaTime);
    void draw(sf::RenderWindow *);

private:
    sf::Vector2f m_pos;
    sf::Vector2f m_prev_pos;
    bool m_locked;
};

#endif
