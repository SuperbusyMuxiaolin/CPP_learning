#pragma once
#include "Worker.hpp"

class Manager : public Worker
{
public:
    Manager(int wID, string name, int dID);

    // 展示员工信息
    virtual void show_info();
};