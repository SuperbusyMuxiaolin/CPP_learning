#pragma once

class Point {
public:
    void set(float x, float y);
    float getX() const;
    float getY() const;

private:
    float m_X{};
    float m_Y{};
};