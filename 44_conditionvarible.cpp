#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> food_queue; // 共享资源：出餐台
void waiter(int id)
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []
                { return !food_queue.empty(); });

        int food = food_queue.front();
        food_queue.pop();

        std::cout << "waiter" << id << "端走了菜品" << food << std::endl;
        lock.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
void chief()
{
    int foodid = 1;
    while (true)
    {
        // 做菜
        std::this_thread::sleep_for(std::chrono::seconds(1));
        {
            std::unique_lock<std::mutex> lock(mtx);
            food_queue.push(foodid);
            std::cout << "chief做好了菜" << foodid << std::endl;
        }
        cv.notify_one();
        foodid++;
    }
}

int main()
{
    std::thread t1(waiter, 1);
    std::thread t2(waiter, 2);
    std::thread t3(chief);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}