#include "Circle.hpp"

Point Circle::getCenter() const {
    return m_Center;
}
float Circle::getR() const {
    return m_R;
}
void Circle::set(Point C, float R){
    m_Center = C;
    m_R = R;
}