#ifndef POINT_H
#define POINT_H

#include <SFML/Graphics.hpp>

class Point {
public:
    Point(int x, int y);
    void lock();

private:
    int m_x, m_y;
    bool m_locked;
};

#endif
