#include <iostream>
#include "myvector.hpp"
#include "mylist.hpp"
void test01()
{
    myvector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.showall();
    v.push_first(10);
    v.showall();
    v.push_index(1, 20);
    v.showall();
    v.pop_index(2);
    v.showall();
    cout << v[20] << endl; // 会异常
}

void test02()
{
    std::vector<int> v = {1, 2, 3};
    MyLinkedList list(v);
    list.showall();
    list.addAtIndex(0, 2);
    list.addAtHead(1);
    list.addAtTail(3);
    list.showall();
    list.deleteAtIndex(1);
    list.showall();
    cout << list.get(0) << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}