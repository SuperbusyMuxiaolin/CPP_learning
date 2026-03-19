#include "Worker.hpp"

void Worker::show_info()
{
    cout << "员工编号:" << this->m_wID << "\t"
         << "员工姓名:" << this->m_Name << "\t"
         << "员工部门编号" << this->m_dID << "\t"
         << "员工职位:" << "未知" << endl;
}
