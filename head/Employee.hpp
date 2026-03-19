#pragma once
#include "Worker.hpp"

class Employee : public Worker
{
public:
    Employee(int wID, string name, int dID);

    // 展示员工信息
    virtual void show_info();
};