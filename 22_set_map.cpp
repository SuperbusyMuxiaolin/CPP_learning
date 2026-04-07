#include <iostream>
#include <set>
using namespace std;

// 如果是自定义数据类型，则必须要自定义比较器
// map的话和set差不多，不过是键值对
class Mycompare
{
public:
    // 加上const，容器内部会把比较器当作 const 对象来调用
    bool operator()(int v1, int v2) const
    {
        return v1 > v2;
    }
};

void printset(const set<int, Mycompare> &s)
{
    for (set<int, Mycompare>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
}
void printset(const multiset<int> &s)
{
    for (multiset<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
}

// set和mutiset的区别
void test01()
{

    set<int, Mycompare> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    s1.insert(50);
    cout << s1.insert(10).second << endl;
    printset(s1);
    multiset<int> s2;
    s2.insert(30);
    s2.insert(30);
    printset(s2);
}

void test02()
{
}

int main()
{
    test01();
}