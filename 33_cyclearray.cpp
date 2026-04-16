#include <iostream>
#include <stdexcept>
#include <vector>
#include <ostream>
using namespace std;

template <typename T>
class CycleArray
{
    std::vector<T> arr;
    int start;
    int end;
    int count;

    void resize(int newsize)
    {
        vector<T> newarr(newsize);
        for (int i = 0; i < count; i++)
        {
            newarr[i] = arr[(start + i) % arr.size()];
        }
        arr = std::move(newarr);
        start = 0;
        end = count;
    }

public:
    // 构造
    CycleArray() : CycleArray(1) {}
    explicit CycleArray(int size) : arr(size), start(0), end(0), count(0) {}

    // 头插
    void addfirst(const T &val)
    {
        if (isFull())
        {
            resize(2 * arr.size());
        }
        start = (start - 1 + arr.size()) % arr.size();
        arr[start] = val;
        count++;
    }
    // 头删
    void removefirst()
    {
        if (isEmpty())
            throw std::runtime_error("Array is Empty");
        arr[start] = T();
        start = (start + 1) % arr.size();
        count--;
        if (count > 0 && count <= arr.size() / 4)
        {
            resize(arr.size() / 2);
        }
    }

    // 尾插
    void addlast(const T &val)
    {
        if (isFull())
        {
            resize(arr.size() * 2);
        }
        arr[end] = val;
        end = (end + 1) % arr.size();
        count++;
    }

    // 尾删
    void removelast()
    {
        if (isEmpty())
            throw std::runtime_error("没有元素可以删除");
        end = (end - 1 + arr.size()) % arr.size();
        arr[end] = T();
        count--;
        if (count > 0 && count <= arr.size() / 4)
        {
            resize(arr.size() / 2);
        }
    }

    // 查首
    T getfirst()
    {
        return arr[start];
    }

    // 查尾
    T getlast()
    {
        return arr[(end - 1 + arr.size()) % arr.size()];
    }

    // tools
    bool isFull()
    {
        return count == arr.size();
    }

    bool isEmpty()
    {
        return count == 0;
    }

    void printall()
    {
        for (int i = start; i != end; i = (i + 1) % arr.size())
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    CycleArray<int> myarr;

    cout << "[1] 初始状态: ";
    myarr.printall();

    cout << "[2] 尾插 1 2 3 4" << endl;
    myarr.addlast(1);
    myarr.addlast(2);
    myarr.addlast(3);
    myarr.addlast(4);
    myarr.printall();
    cout << "首元素: " << myarr.getfirst() << ", 尾元素: " << myarr.getlast() << endl;

    cout << "[3] 头插 100 200" << endl;
    myarr.addfirst(100);
    myarr.addfirst(200);
    myarr.printall();
    cout << "首元素: " << myarr.getfirst() << ", 尾元素: " << myarr.getlast() << endl;

    cout << "[4] 头删一次、尾删一次" << endl;
    myarr.removefirst();
    myarr.removelast();
    myarr.printall();
    cout << "首元素: " << myarr.getfirst() << ", 尾元素: " << myarr.getlast() << endl;

    cout << "[5] 连续删除直到空，触发缩容路径" << endl;
    while (!myarr.isEmpty())
    {
        myarr.removefirst();
        myarr.printall();
    }

    cout << "[6] 空数组删除异常测试" << endl;
    try
    {
        myarr.removefirst();
    }
    catch (const std::exception &e)
    {
        cout << "捕获异常: " << e.what() << endl;
    }

    return 0;
}