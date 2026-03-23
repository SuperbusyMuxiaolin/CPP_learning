#pragma once
#include <iostream>
#include <fstream>
#include <cctype>
#include "Worker.hpp"
#include "Boss.hpp"
#include "Manager.hpp"
#include "Employee.hpp"

#define FILENAME "workers.txt"

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

    // 保存职工信息到txt文件
    void save();

    // 修改职工
    void modify();

    // 按编号或者姓名查找指定员工
    void look();

    // 按员工编号进行排序
    void sort();

    // 清空文件
    void clean();

    // 析构函数
    ~WorkerManage();

    int worker_num;

    bool file_empty;

    Worker **worker_p_array;
};
