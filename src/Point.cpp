#include "Point.h"

Point::Point(int x, int y) : m_x(x), m_y(y) {}

void Point::lock() { m_locked = true; }
