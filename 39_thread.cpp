#include <iostream>
#include <thread>

struct Data
{
    Data() = default;
    Data(const Data &) { std::cout << "拷贝构造" << std::endl; }
    // Data(const Data&) = delete;
    Data(Data &&) { std::cout << "移动构造" << std::endl; }
    // Data(Data&&) = delete;
    int value{0};
};

void do_work1(Data data)
{
    data.value = 200;
}

void do_work2(Data &&data)
{
    data.value = 200;
}

void do_work(Data &data)
{
    data.value = 200;
}

// 1. 左值方式传递
void test01()
{
    Data data;
#if 1
    // 拷贝构造函数（复制到内部元组tuple） -> 移动构造函数(内部转化为右值直接绑定到右值引用参数上)
    auto do_work = do_work1;
#else
    // 拷贝构造函数 （复制到内部元组tuple）
    auto do_work = do_work2;

#endif
    std::thread t(do_work, data);
    t.join();
}

// 2. 右值方式传递
void test02()
{
    Data data;
#if 1
    // 移动构造函数 -> 移动构造函数(内部转化为右值直接绑定到右值引用参数上)
    auto do_work = do_work1;
#else
    // 移动构造函数
    auto do_work = do_work2;

#endif
    std::thread t(do_work, std::move(data));
    t.join();
}

void test03()
{

    Data data;
    std::thread t(do_work, std::ref(data));
    t.join();
    std::cout << data.value << std::endl;
}

int main()
{
    // test01();
    test03();
    return 0;
}