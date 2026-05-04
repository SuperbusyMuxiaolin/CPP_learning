#include <iostream>
#include <mutex>
#include <thread>

int total_tickets = 10;
std::mutex mtx;

void sell_ticket(std::string user)
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        mtx.lock();
        if (total_tickets > 0)
        {
            std::cout << "窗口——" << user << "卖出了票，剩余" << total_tickets - 1 << "张票" << std::endl;
            total_tickets--;
            mtx.unlock();
        }
        else
        {
            std::cout << "窗口——" << user << "发现票已卖光" << std::endl;
            mtx.unlock();
            break;
        }
    }
}
int main()
{
    std::thread t1(sell_ticket, "A");
    std::thread t2(sell_ticket, "B");

    t1.join();
    t2.join();
    return 0;
}