#pragma once
#include "Worker.hpp"

class Boss : public Worker
{
public:
    Boss(int wID, string name, int dID);

    // 展示员工信息
    virtual void show_info();
};