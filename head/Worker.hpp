#pragma once
#include <iostream>
#include <string>
using namespace std;

class Worker
{
public:
    // 展示Worker信息
    virtual void show_info();

    virtual ~Worker() {};
    // Worker属性
    int m_wID;
    string m_Name;
    int m_dID;
};