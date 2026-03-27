#pragma once

class Point
{
public:
    Point()
    {
    }
    Point(int a, int b)
    {
        this->m_X = a;
        this->m_Y = b;
    }

    void set(float x, float y);
    float getX() const;
    float getY() const;

private:
    float m_X{};
    float m_Y{};
};