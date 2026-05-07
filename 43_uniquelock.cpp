#include <mutex>
#include <shared_mutex>
#include <thread>

std::mutex mtx1;
std::recursive_mutex mtx2;
std::shared_mutex mtx3;
std::timed_mutex mtx4;

void test01()
{
    {
        std::unique_lock<std::mutex> lock(mtx1);
    }
    {
        std::unique_lock<std::mutex> lock(mtx1);
        mtx1.unlock();
    }
    {
        std::unique_lock<std::mutex> lock(mtx1);
        std::mutex *mtx = lock.release();
        mtx->unlock();
    }

    {
        std::unique_lock<std::recursive_mutex> lock(mtx2);
        std::unique_lock<std::recursive_mutex> lock2(mtx2);
    }
}
void test02()
{
    {
        mtx1.lock();
        std::unique_lock<std::mutex> lock(mtx1, std::adopt_lock);
    }
    {
        std::unique_lock<std::mutex> lock(mtx1, std::defer_lock);
        lock.lock();
    }
    {
        std::unique_lock<std::mutex> lock(mtx1, std::try_to_lock);
        if (lock.owns_lock())
        {
        }
        else
        {
        }
    }
    {
        std::unique_lock<std::timed_mutex> lock(mtx4, std::chrono::seconds(3));
        if (lock.owns_lock())
        {
        }
        else
        {
        }
    }
}
