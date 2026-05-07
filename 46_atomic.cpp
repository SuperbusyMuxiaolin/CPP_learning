#include <iostream>
#include <atomic>
#include <thread>
class Demo
{
public:
    Demo() { std::cout << "Demo 构造函数" << std::endl; }
    int a;
    int b;
    // 包含以下内容，该对象不再是简单的对象，atomic 编译会报错
    // Demo(const Demo&) {}
    // Demo(Demo&&) {}
    // Demo& operator=(const Demo&) {}
    // Demo& operator=(Demo&&) {}
    // virtual void func() {}
    // ~Demo() {}
    // int &mem_ref;
};
void demo()
{
    std::atomic<int> a(0);
    std::atomic<char> ac('h');
    std::atomic<bool> ab(true);

    std::atomic<char *> pc(nullptr);
    std::atomic<void *> pv(nullptr);

    std::atomic<Demo> ad;
}

void demo01()
{
    std::atomic<int> ai(0);
    int ai_value = ai.load();
    // ai.store(30);
    ai = 20;
    int oldvalue = ai.exchange(30);
    std::cout << oldvalue << "  " << ai << std::endl;
}

std::atomic<int> ai(0);
std::mutex mtx;
void worker()
{
    for (int i = 0; i < 100; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        int oldvalue = ai.load();
        int newvalue;

        do
        {
            newvalue = (oldvalue == 20) ? 0 : oldvalue + 1;
        } while (!ai.compare_exchange_strong(oldvalue, newvalue));
        mtx.lock();
        std::cout << ai << "\t" << std::this_thread::get_id() << std::endl;
        mtx.unlock();
    }
}
void demo02()
{
    std::thread t1(worker);
    std::thread t2(worker);
    t1.join();
    t2.join();
}

int main()
{
    demo02();
}