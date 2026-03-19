#include "Boss.hpp"

Boss::Boss(int wID, string name, int dID)
{
    this->m_wID = wID;
    this->m_Name = name;
    this->m_dID = dID;
}

void Boss::show_info()
{
    cout << "员工编号:" << this->m_wID << "\t"
         << "员工姓名:" << this->m_Name << "\t"
         << "员工部门编号" << this->m_dID << "\t"
         << "员工职位:" << "老板" << endl;
}
