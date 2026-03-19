#include "WorkerManage.hpp"
#include "Employee.hpp"
#include "Manager.hpp"
#include "Boss.hpp"

int main()
{
    WorkerManage wm;

    while (true)
    {
        wm.show_menu();
        int select = -1;
        cout << "请输入选项" << endl;
        cin >> select;
        switch (select)
        {
        case 0:
            wm.exit_system();
            break;
        case 1:
            wm.add_worker();
            break;
        case 2:
            wm.show_workers();
            break;
        case 3:
            wm.delete_worker();
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        default:
            break;
        }
    }

    std::cout << "test" << std::endl;
    return 0;
}