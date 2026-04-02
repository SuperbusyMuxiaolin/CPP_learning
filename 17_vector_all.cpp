// vector可以动态扩展，当vector的size超过capacity时，vector会自动扩展容量，通常是将容量增加一倍，以减少频繁的扩展操作。
// vector的扩展不是在原有的后面扩展，而是会找更大的空间来存储数据，并将原有的数据复制到新的空间中，然后释放原有的空间。

#include <iostream>
#include <vector>

using namespace std;

void printvector(const std::vector<int> &v)
{
    // for(std::vector<int>::iterator t= v.begin();t!=v.end();t++){
    //     std::cout<<*t<<std::endl;
    // }
    for (auto t : v)
    {
        std::cout << t << "\n";
    }
}

// 一些构造函数
void test01()
{
    std::vector<int> v1;
    for (int i = 0; i < 5; i++)
    {
        v1.push_back(i);
    }
    printvector(v1);
    vector<int> v2(v1.begin() + 1, v1.end() - 1);
    printvector(v2);
    vector<int> v3(10, 5);
    printvector(v3);
}
void test02()
{
    vector<int> v1;
    for (static int i = 0; i < 5; i++)
    {
        v1.push_back(i);
    }
    printvector(v1);
    // static关键词修饰的i只是生命周期长，作用域其实在循环内，
    // cout<<i<<endl;
    vector<int> v2 = v1;
    printvector(v2);
    vector<int> v3;
    v3.assign(v1.begin(), v1.end());
    printvector(v3);
    vector<int> v4;
    v4.assign(3, 8);
    printvector(v4);
}

void test03()
{
    vector<int> v1;
    for (static int i = 0; i < 5; i++)
    {
        v1.push_back(i);
    }
    printvector(v1);
    cout << "size:" << v1.size() << endl;
    cout << "capacity:" << v1.capacity() << endl;
    cout << v1.empty() << endl;
    v1.resize(10);
    printvector(v1);
    cout << "size:" << v1.size() << endl;
    cout << "capacity:" << v1.capacity() << endl;
}
void test04()
{
    vector<int> v1;
    for (static int i = 0; i < 5; i++)
    {
        v1.push_back(i);
    }
    printvector(v1);
    v1.pop_back();
    printvector(v1);
    v1.insert(v1.begin() + 1, 20);
    printvector(v1);
    v1.erase(v1.begin() + 1);
    printvector(v1);
    v1.clear();
    printvector(v1);
}
void test05()
{
    vector<int> v1;
    for (static int i = 0; i < 5; i++)
    {
        v1.push_back(i);
    }
    printvector(v1);
    cout << v1.at(2) << endl;
    cout << v1[2] << endl;
    cout << v1.front() << endl;
    cout << v1.back() << endl;
}

void test06()
{
    vector<int> v1;
    for (static int i = 0; i < 5; i++)
    {
        v1.push_back(i);
    }
    printvector(v1);
    cout << "cpacity:" << v1.capacity() << endl;
    vector<int> v2{1, 2, 3};
    v1.swap(v2);
    cout << "交换后cpacity:" << v1.capacity() << endl;
    printvector(v1);
    // 利用swap压缩内存，
    // v1.shrink_to_fit();用这个压缩更直接
    vector<int>(v1).swap(v1);
    cout << "和自己交换压缩后cpacity:" << v1.capacity() << endl;
}

int main()
{
    // test01();
    // test02();
    // test03();
    // test04();
    test06();
    return 0;
}