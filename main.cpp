#include <iostream>
#include "myvector.hpp"
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
    cout << v[20] << endl;
}
int main()
{
    test01();
    return 0;
}