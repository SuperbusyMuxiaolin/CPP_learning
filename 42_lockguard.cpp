#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <condition_variable>

std::mutex mtx1;
std::timed_mutex mtx2;
std::shared_mutex mtx3;
std::recursive_mutex mtx4;

void test()
{
    {
        std::lock_guard<std::mutex> lock(mtx1); // lock_guard对象创建时自动加锁，销毁时自动解锁
        // auto lk2 = std::move(lock);
    }
    {
        std::lock_guard<std::recursive_mutex> lock(mtx4);
    }
    {
        std::lock_guard<std::timed_mutex> lock(mtx2);
    }
    {
        std::lock_guard<std::shared_mutex> lock(mtx3);
    }
}

void test02()
{
    mtx1.lock();
    std::lock_guard<std::mutex> lock(mtx1, std::adopt_lock);
}