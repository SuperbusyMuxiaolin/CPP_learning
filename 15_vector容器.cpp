#include <iostream>
#include <vector>
#include <algorithm>

void myprint(int a)
{
    std::cout << a << std::endl;
}
void test01()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::for_each(v.begin(), v.end(), myprint);
}

int main()
{
    test01();
    return 0;
}