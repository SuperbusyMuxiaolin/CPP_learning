#pragma once
#include <iostream>

template <class T>
class Mylist
{
public:
    Mylist(int cap)
    {
        std::cout << "有参构造函数" << std::endl;
        this->Capacity = cap;
        this->Size = 0;
        this->arr = new T[this->Capacity];
    }

    Mylist(const Mylist &list)
    {
        std::cout << "深度拷贝" << std::endl;
        this->Capacity = list.Capacity;
        this->Size = list.Size;
        this->arr = new T[this->Capacity];
        for (int i = 0; i < this->Size; i++)
        {
            this->arr[i] = list.arr[i];
        }
    }

    Mylist &operator=(const Mylist &list)
    {
        if (this = &list)
        {
            return *this;
        }
        if (this->arr != NULL)
        {
            delete[] this->arr;
        }
        this->Capacity = list.Capacity;
        this->Size = list.Size;
        this->arr = new T[this->Capacity];
        for (int i = 0; i < this->Size; i++)
        {
            this->arr[i] = list.arr[i];
        }
        return *this;
    }

    void push_back(const T &t)
    {
        if (this->Size == this->Capacity)
        {
            std::cout << "超过容量限制" << std::endl;
            return;
        }
        this->arr[this->Size] = t;
        this->Size++;
    }

    void remove_back()
    {
        if (this->Size == 0)
        {
            std::cout << "List已清空，不能再删除" << std::endl;
            return;
        }
        this->Size--;
    }

    int get_capacity()
    {
        return this->Capacity;
    }

    int get_size()
    {
        return this->Size;
    }

    T &operator[](int index)
    {
        return this->arr[index];
    }

    ~Mylist()
    {
        std::cout << "析构函数" << std::endl;
        if (this->arr != NULL)
        {
            delete[] arr;
            arr = NULL;
        }
    }

private:
    T *arr;
    int Capacity;
    int Size;
};