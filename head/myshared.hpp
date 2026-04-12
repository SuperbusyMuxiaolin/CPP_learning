#pragma once
#include <iostream>
using namespace std;

// template <typename T>
class ControlBlock
{
public:
    int strong_ref = 0;

    ControlBlock()
    {
        cout << "控制块构造" << endl;
        strong_ref = 0;
    }

    ~ControlBlock()
    {
        cout << "控制块析构" << endl;
    }

    void increment()
    {
        strong_ref++;
    }

    void down()
    {
        strong_ref--;
    }

    int get_strongref()
    {
        return strong_ref;
    }
};

template <typename T>
class MySharedptr
{
public:
    // 默认构造函数
    MySharedptr() = default;
    // 构造函数

    // down and release
    void down_release()
    {
        if (this->ref != nullptr)
        {
            this->ref->down();
            if (this->ref->get_strongref() == 0)
            {
                delete ref;
                delete object;          // object为空也可以delete它
                this->ref = nullptr;    // 养成好习惯
                this->object = nullptr; // 养成好习惯
            }
        }
    }

    MySharedptr(T *t)
    {
        cout << "智能指针对象构造" << endl;
        this->object = t;
        this->ref = new ControlBlock();
        this->ref->increment();
    }
    // 拷贝构造函数
    MySharedptr(const MySharedptr &p)
    {
        cout << "智能指针拷贝构造" << endl;
        this->object = p.object;
        this->ref = p.ref;
        if (this->ref != nullptr)
        {
            this->ref->increment();
        }
    }
    // 拷贝赋值
    MySharedptr &operator=(const MySharedptr &p)
    {
        cout << "智能指针拷贝赋值" << endl;
        if (this == &p)
        {
            return *this;
        }
        // 对当前对象管理的旧资源进行处理
        this->down_release();
        this->object = p.object;
        this->ref = p.ref;
        if (this->ref != nullptr)
        {
            this->ref->increment();
        }
        return *this;
    }

    // 移动构造
    MySharedptr(MySharedptr &&p)
    {
        cout << "智能指针移动构造" << endl;
        this->object = p.object;
        this->ref = p.ref;
        p.object = nullptr;
        p.ref = nullptr;
    }
    // 移动赋值
    MySharedptr &operator=(MySharedptr &&p)
    {
        cout << "智能指针移动赋值" << endl;
        if (this == &p)
        {
            return *this;
        }
        // 对当前对象管理的旧资源进行处理
        this->down_release();
        this->object = p.object;
        this->ref = p.ref;
        p.object = nullptr;
        p.ref = nullptr;
        return *this;
    }

    // 重载*
    T &operator*() const
    {
        return *this->object;
    }

    T *operator->() const
    {
        return this->object;
    }

    void reset()
    {
        if (this->ref == nullptr)
        {
            return;
        }
        this->down_release();
        this->ref = nullptr;
        this->object = nullptr;
    }

    void reset(T *p)
    {
        this->down_release();
        this->object = p;
        this->ref = new ControlBlock();
        this->ref->increment();
    }

    explicit operator bool() const
    {
        return this->object != nullptr;
    }

    ~MySharedptr()
    {
        if (this->ref == nullptr)
        {
            return;
        }
        cout << "智能指针对象析构" << endl;
        this->down_release();
    }

private:
    T *object = nullptr;
    ControlBlock *ref = nullptr;
};
