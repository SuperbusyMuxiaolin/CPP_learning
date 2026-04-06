#include <iostream>
#include <list>

using namespace std;
void printlist(const list<int> &ls)
{
    for (list<int>::const_iterator it = ls.begin(); it != ls.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
}

void test01()
{
    // 接口与前面的其实都差不多，多了一个remove，可以剔除容器中所有与element相同的元素
}

int main()
{
    test01();
}