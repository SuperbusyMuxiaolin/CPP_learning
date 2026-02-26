#pragma once
#include "Point.hpp"

class Circle{
    public:
        Point getCenter() const;
        float getR() const;
        void set(Point C, float R);
    private:
        float m_R;
        Point m_Center;
};
