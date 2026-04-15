#pragma once
#include <iostream>
using namespace std;

template <typename T>
class myvector
{
public:
    // 构造
    myvector()
    {
        int cap = 5;
        int size = 0;
        T *data = new T[cap];
    }

    // 越界
    bool checkindex(int index)
    {
        return !(0 <= index && index < this->size);
    }

    // 扩容函数
    void expand()
    {
        if (this->size == this->cap)
        {
            cout << "容量不足, 需要扩容" << endl;
            this->cap = 2 * this->cap;
            T *datanew = new T[this->cap];
            for (int i = 0; i < this->size; i++)
            {
                datanew[i] = data[i];
            }
            delete[] data;
            this->data = datanew;
        }
    }

    void compress()
    {
        if (this->size == this->cap / 2 && this->cap > 5)
        {
            cout << "容量充足, 可以缩容" << endl;
            this->cap = this->cap / 2;
            T *newdata = new T[this->cap];
            for (int i = 0; i < this->size; i++)
            {
                newdata[i] = this->data[i];
            }
            delete[] this->data;
            this->data = newdata;
        }
    }

    // 增
    void push_back(const T &t) // 既可以接收左值引用，也可以接收右值引用
    {
        this->expand();
        this->data[size] = t;
        this->size++;
    }

    void push_index(int index, const T &t)
    {
        if (this->checkindex(index))
        {
            cout << "索引越界" << endl;
            return;
        }
        this->expand();
        for (int i = this->size; i > index; i--)
        {
            this->data[i] = this->data[i - 1];
        }
        this->data[index] = t;
        this->size++;
    }

    void push_first(const T &t)
    {
        push_index(0, t);
    }

    // 删
    void pop_back()
    {
        if (this->size == 0)
        {
            cout << "数组为空" << endl;
            return;
        }
        this->compress();
        this->size--;
    }

    void pop_index(int index)
    {
        if (this->size == 0)
        {
            cout << "数组为空" << endl;
            return;
        }
        this->compress();
        if (this->checkindex(index))
        {
            cout << "索引越界" << endl;
            return;
        }
        for (int i = index; i < this->size - 1; i++)
        {
            this->data[i] = this->data[i + 1];
        }
        this->size--;
    }

    void pop_first()
    {
        pop_index(0);
    }

    // 查
    T get_last()
    {
        if (this->size == 0)
        {
            cout << "数组为空" << endl;
            return;
        }
        return this->data[this->size - 1];
    }

    T get_index(int index)
    {
        if (this->size == 0)
        {
            cout << "数组为空" << endl;
            return;
        }
        if (this->checkindex(index))
        {
            cout << "索引越界" << endl;
            return;
        }
        return this->data[index];
    }

    T &operator[](int index)
    {
        if (this->size == 0 || this->checkindex(index))
            throw std::out_of_range("myvector: index out of range");
        return this->data[index];
    }

    void showall()
    {
        cout << "容器内的值为：";
        for (int i = 0; i < this->size; i++)
        {
            cout << this->data[i] << "  ";
        }
        cout << endl;
    }

    // xigou
    ~myvector()
    {
        if (this->data != nullptr)
        {
            delete[] this->data;
            this->data = nullptr;
        }
    }

private:
    int cap = 0;
    int size = 0;
    T *data = nullptr;
};