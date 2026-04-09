#include <iostream>
#include <vector>
using namespace std;

class Demo
{
public:
    Demo(int n)
    {
        m_size = n;
        p_arr = new int[m_size];
        for (int i = 0; i < 10; ++i)
        {
            p_arr[i] = 100 + i;
        }
        cout << "默认构造" << endl;
    }

    Demo(const Demo &demo)
    {
        m_size = demo.m_size;
        p_arr = new int[m_size];
        for (int i = 0; i < 10; ++i)
        {
            p_arr[i] = demo.p_arr[i];
        }
        cout << "拷贝构造" << endl;
    }

    // 移动构造
    Demo(Demo &&demo)
    {
        cout << "移动构造" << endl;
        // 移动资源
        m_size = demo.m_size;
        p_arr = demo.p_arr;
        // 释放原有资源
        demo.p_arr = nullptr;
        demo.m_size = 0;
    }

    Demo &operator=(const Demo &demo)
    {
        if (this == &demo)
        {
            return *this;
        }
        m_size = demo.m_size;
        if (p_arr != nullptr)
        {
            delete[] p_arr;
            p_arr = nullptr;
        }
        p_arr = new int[m_size];
        for (int i = 0; i < 10; ++i)
        {
            p_arr[i] = demo.p_arr[i];
        }
        cout << "拷贝赋值" << endl;
        return *this;
    }

    // 移动赋值
    Demo &operator=(Demo &&demo)
    {
        cout << "移动赋值" << endl;
        m_size = demo.m_size;
        if (p_arr != nullptr)
        {
            delete[] p_arr;
            // p_arr = nullptr;
        }
        p_arr = demo.p_arr;
        // 释放原有资源
        demo.p_arr = nullptr;
        demo.m_size = 0;
        return *this;
    }

    ~Demo()
    {
        if (p_arr != nullptr)
        {
            delete[] p_arr;
            p_arr = nullptr;
        }
        cout << "析构函数" << endl;
    }

public:
    int *p_arr;
    int m_size;
};

Demo create_demo()
{
    Demo demo1(10);
    Demo demo2(15);

    if (demo1.m_size > demo2.m_size)
    {
        return demo1;
    }
    return demo2;
}

// 1. 返回局部对象
void test01()
{
    // create_demo 返回临时对象
    // 在销毁之前，需要调用拷贝构造函数
    Demo demo = create_demo();
}

// 2. 值方式传参
void do_logic(const Demo &demo) {}
void test02()
{
    // create_demo 返回临时对象会调用拷贝构造函数
    // 绑定到常量引用，生命周期延长到下面这句话结束
    do_logic(create_demo());
}

// 3. 容器操作
void test03()
{
    vector<Demo> vec;
    // 将临时对象拷贝到容器中
    vec.push_back(Demo(10));
}

// 4. 交换两个对象
void test04()
{
    Demo demo1(10);
    Demo demo2(20);
    swap(demo1, demo2);
}

// 5. 对象赋值
void test05()
{
    Demo demo(10);

    // 将对象拷贝赋值给 demo 对象
    demo = create_demo();
}

// 6. 容器中元素赋值
void test06()
{
    vector<Demo> vec;
    vec.push_back(Demo(10));
    vec[0] = Demo(10);
}

// 通过将函数参数设置为右值引用和左值引用，实现了函数重载，来区分传入的参数是左值还是右值，从而调用不同的函数版本。
void func(Demo &demo)
{
    cout << "左值引用版本" << endl;
}

void func(Demo &&demo)
{
    cout << "右值引用版本" << endl;
}

int main()
{
    cout << "----test01----" << endl;
    test01();
    cout << "----test02----" << endl;
    test02();
    cout << "----test03----" << endl;
    test03();
    cout << "----test04----" << endl;
    test04();
    cout << "----test05----" << endl;
    test05();
    cout << "----test06----" << endl;
    test06();
    return 0;
}
