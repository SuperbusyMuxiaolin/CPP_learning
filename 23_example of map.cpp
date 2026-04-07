#include <iostream>
#include <map>
#include <vector>
// 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
// 员工信息有: 姓名 工资组成；部门分为：策划0、美术1、研发2
// 随机给10名员工分配部门和工资
// 通过multimap进行信息的插入 key(部门编号) value(员工)
// 分部门显示员工信息

using namespace std;
class Worker
{
public:
    Worker(string name, int sa)
    {
        this->name = name;
        this->salary = sa;
    }
    string name;
    int salary;
};

void createWorker(vector<Worker> &v)
{
    string nameseed = "ABCDEFGHIJ";
    string name = "员工";
    for (int i = 0; i < 10; i++)
    {
        Worker w(name + nameseed[i], rand() % 10001 + 10000);
        v.push_back(w);
    }
}

void allocate(vector<Worker> &v, multimap<int, Worker> &m)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        m.insert(pair(rand() % 3, *it));
    }
}

void printmap(multimap<int, Worker> &m)
{
    multimap<int, Worker>::iterator first = m.begin();
    multimap<int, Worker>::iterator second = m.find(1);
    multimap<int, Worker>::iterator third = m.find(2);
    multimap<int, Worker>::iterator last = m.end();
    cout << "策划人员如下：" << endl;
    for (multimap<int, Worker>::iterator it = first; it != second; it++)
    {
        cout << "姓名：" << it->second.name << " 薪水：" << it->second.salary << endl;
    }
    cout << "美术人员如下：" << endl;
    for (multimap<int, Worker>::iterator it = second; it != third; it++)
    {
        cout << "姓名：" << it->second.name << " 薪水：" << it->second.salary << endl;
    }
    cout << "策划人员如下：" << endl;
    for (multimap<int, Worker>::iterator it = third; it != last; it++)
    {
        cout << "姓名：" << it->second.name << " 薪水：" << it->second.salary << endl;
    }
}

int main()
{
    vector<Worker> v;
    createWorker(v);
    multimap<int, Worker> m;
    allocate(v, m);
    printmap(m);
    return 0;
}
