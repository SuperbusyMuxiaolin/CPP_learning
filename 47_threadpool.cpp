#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <vector>
#include <functional>
#include <condition_variable>

class threadpool
{
public:
    threadpool(size_t size) : stop(false)
    {
        for (int i = 0; i < size; i++)
        {
            workers.emplace_back([this]
                                 {
                while(true){
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(mtx);
                        cv.wait(lock, [this]{
                            return !tasks.empty() || stop;
                        });
                        if (stop && tasks.empty()) {
                            return; // 如果线程池已停止且任务队列为空，退出退出该线程
                        }
                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    task();
                } });
        }
    }

    ~threadpool()
    {
        stop = true;
        cv.notify_all();
        for (auto &w : workers)
        {
            w.join();
        }
    }

    void submit(std::function<void()> ta)
    {
        std::unique_lock<std::mutex> lock(mtx);
        tasks.emplace(std::move(ta));
        lock.unlock();
        cv.notify_one();
    }

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex mtx; // 保护任务队列的
    std::condition_variable cv;
    std::atomic<bool> stop;
};

int main()
{
    threadpool pool(4);
    for (int i = 0; i < 10; i++)
    {
        pool.submit([i]
                    { std::cout << "task " << i << " is running in thread " << std::this_thread::get_id() << std::endl; });
    }
    return 0;
}