#include "Point.hpp"

void Point::set(float x, float y){
    m_X = x;
    m_Y = y;
}

float Point::getX() const {
    return m_X;
}

float Point::getY() const {
    return m_Y;
}