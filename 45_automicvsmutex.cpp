#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>

// int count = 0;
// std::mutex mtx1;
// void worker1()
// {
//     for (int i = 0; i < 2000000; i++)
//     {
//         mtx1.lock();
//         count++;
//         mtx1.unlock();
//     }
// }

std::atomic<int> count(0);
void worker2()
{
    for (int i = 0; i < 2000000; i++)
    {
        count++;
    }
}

int main()
{
    auto start = std::chrono::steady_clock::now();
    std::thread t1(worker2);
    std::thread t2(worker2);
    t1.join();
    t2.join();
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "count = " << count << " time = " << duration.count() << std::endl;
}