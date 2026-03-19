#pragma once
#include <iostream>
#include "Worker.hpp"
#include "Boss.hpp"
#include "Manager.hpp"
#include "Employee.hpp"

using namespace std;

class WorkerManage
{
public:
    // 构造函数
    WorkerManage();

    // 主菜单界面
    void show_menu();

    // 退出功能
    void exit_system();

    // 增加员工
    void add_worker();

    // 展示所有员工
    void show_workers();

    // 找到员工索引
    int find_worker(int id);

    // 删除离职员工
    void delete_worker();

    // 析构函数
    ~WorkerManage();

    int worker_num = 0;

    Worker **worker_p_array = NULL;
};
